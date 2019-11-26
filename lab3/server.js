const express = require("express");
const server = express();
const bodyParser = require('body-parser');
const cookieParser = require('cookie-parser');
const http = require('http');
let socket = require('socket.io');
const debug = require('debug')('httpname');
let Rollbar = require('rollbar');
let rollbar = new Rollbar('12eda24043fa47c4bddfcc835ac047a3');
server.use(express.static('./public/images'));
server.use(express.static('./public/src'));
server.use(express.static('./public/less'));
server.use(cookieParser());
server.use(bodyParser.json());
server.use(bodyParser.urlencoded({extended:true}));
server.set('view engine', 'pug');
server.set('views','./views');
/*
let list = require('./public/src/List');
let participants = require('./public/src/Participants');
let settings = require('./public/src/settings');
 */

const pug = require('pug');
let settings = require('./public/src/settings');
let Picture = require('./public/src/Picture');
let list = require('./public/src/List');
let participants = require('./public/src/Participants');
let multer = require('multer');
const path = require("path");
let Participant = require('./public/src/Participant');

let name = "";

settings.curBuyer.value = 0;
settings.curBuyer.buyer = null;
let fs = require('fs');
fs.writeFile('./public/json/settings.json', JSON.stringify(settings), (err) => {

});

let app = http.createServer(server).listen(3000, function(){

});

let io = socket.listen(app);

io.sockets.on('connection', (socket)=>{

    socket.on('chat message', function(msg){
        let d = new Date();
        if(socket.username=="admin")
            io.emit('chat message',d.getHours()+":"+d.getMinutes()+":"+d.getSeconds()+": "+socket.username+': '+ msg);
        if(socket.username!="admin") {
            if (parseInt(msg) > settings.curBuyer.value) {
                console.log(participants.participants[socket.id_].networth)
                if(parseInt(msg)<=participants.participants[socket.id_].networth) {
                    settings.curBuyer.buyer = socket.username;
                    settings.curBuyer.value = parseInt(msg);
                    settings.curBuyer.id = socket.id_;
                    io.emit('chat message', d.getHours() + ":" + d.getMinutes() + ":" + d.getSeconds() + ": " + socket.username + ': Bet ' + msg);
                    let fs = require('fs');
                    fs.writeFile('./public/json/settings.json', JSON.stringify(settings), (err) => {

                    });
                }else{
                    io.to(`${socket.id}`).emit('chat message',"ERROR4");
                }
            }else{
                io.to(`${socket.id}`).emit('chat message',"ERROR1");
            }
        }
    });

    socket.on('username', function(username) {
        if(parseInt(username)>=participants.participants.length) {
            rollbar.log('ERROR with id');
            io.to(`${socket.id}`).emit('tmp',"ERROR3");
            return
        }
        try {
            if (parseInt(username) == -1) {
                socket.username = "admin";
                socket.id_ = -1;
            } else {
                if(participants.participants[parseInt(username)].inAuc=='No'){
                    rollbar.log('ERROR with id, you are not allowed to play this game');
                    io.to(`${socket.id}`).emit('tmp1',"ERROR4");
                    return
                }
                socket.username = participants.participants[parseInt(username)].name;
                socket.id_ = parseInt(username);
            }
            io.emit('online', socket.username)
        }catch (e) {
            rollbar.log(e);
        }
    });

    socket.on('time', function(data) {
        io.emit('timer', data);
    });

    socket.on('end', function (e) {
       io.emit('end', parseInt(settings.duration)-parseInt(e));
       try {
           if (parseInt(settings.duration) - parseInt(e) == 0) {
               io.emit('aucend', settings.curBuyer.buyer);
               list.list[settings.curLot.id].inAuction = "No";
               list.save();
               participants.participants[settings.curBuyer.id].paints.push({x:'http://localhost:3000/paint/' + settings.curLot.id, y:list.list[settings.curLot.id].name});
               participants.participants[settings.curBuyer.id].networth  -=settings.curBuyer.value;
               settings.curLot = null;
               settings.curBuyer.buyer = null;
               settings.curBuyer.value = null;
               participants.save();
           }
       }catch (e) {
           rollbar.log(e);
       }
    });

    socket.on('notstarted', function (e){
        io.to(`${socket.id}`).emit('tmp',"ERROR2");
    });
});

const storage = multer.diskStorage({
    destination:(req, file, cd)=>{
        cd(null, './public/images')
    },
    filename:(req,  file, cb)=>{
        cb(null, (name)+path.extname(file.originalname))
    }
});

const upload = multer({
    storage,
    limits:{fileSize: 10*1024*1024},
    fileFilter:(req, file, cb)=>{
        const ext = path.extname(file.originalname);
        if(ext!=='.jpg'){
            const er = new Error('Extencion');
            er.code = 'extencion';
            return cb(er);
        }
        cb(null, true);
    }
}).single('file');

server.get('/',(req, res, next)=>{

    settings.participants = participants.participants.filter((e)=>{
        return e.inAuc==="Yes";
    });

    settings.paintings = list.list.filter((e)=>{
        return e.inAuction==="Yes";
    });
    res.render('index',{
        x: settings
    });
});

server.delete('/paint/:num', (req, res)=>{
    let x = req.params.num;
    list.list.splice(x, 1);
    for(let i = x;i<list.list.length;i++){
        list.list[i].id--;
    }
    res.status(200);
    res.send("/paintings");
    list.save()
});

server.post('/image/:num', (req, res)=>{
    let x = req.params.num;
    upload(req, res, err=>{
    });
    res.status(200);
    res.sendFile(__dirname+'/public/images/'+x+'.jpg');
});

server.put('/paint/:num', (req, res)=>{
    let x1 =req.params.num;
    name = list.list[x1].img;
    name = name.split('.');
    name = name[0];
    upload(req, res, err=>{
    });
    res.status(200);
    //res.end(pug.compileFile('./views/img.pug')({x:list.list[x1]}));
    res.send(JSON.stringify(list.list[x1]))
});

server.post('/participants', (req, res)=>{
    let tmp = req.body;
    let x = new Participant();
    x.id = participants.participants.length;
    x.name = tmp.name;
    x.inAuc = "Yes";
    x.location = tmp.location;
    x.coord.x = tmp.x;
    x.coord.y = tmp.y;
    x.networth = 100;
    participants.participants.push(x);
    participants.save();
    res.status(200);
    res.send(pug.compileFile('./views/participants.pug')({participants:participants.participants}));
});

server.post('/', (req, res)=>{
    let tmp = req.body;
    settings.date = tmp.date;
    settings.time = tmp.time;
    settings.time_out = tmp.out;
    settings.duration = tmp.duration;
    settings.pause = tmp.pause;
    let fs = require('fs');
    fs.writeFile('./public/json/settings.json', JSON.stringify(settings), (err)=>{

    });
});

server.post('/image',(req, res)=>{
    upload(req, res, err=>{
        res.json()
    });
});

server.get('/paintings', (req, res, next)=>{
    res.render('paintings', {
        paintings:list.list
    });
});

server.get('/paint/:num', (req, res, next)=>{
    let _id = req.params.num;
    //list.list[_id].img = _id+'.jpg';
    res.render('paint', {
        x:list.list[_id]
    });
});

server.delete('/participant/:num',(req, res, next)=>{
    let x = req.params.num;
    participants.participants.splice(x, 1);
    for(let i = x;i<participants.participants.length;i++){
        participants.participants[i].id--;
    }
    res.status(200);
    res.send("/participants");
    participants.save();
});
server.get('/participants', (req, res, next)=>{
    res.render('participants', {
        participants: participants.participants
    });
});

server.post('/paint/:num', (req, res, next)=>{
    let x  = req.params.num;
    let tmp = req.body;
    list.list[x].name = tmp.name;
    list.list[x].author = tmp.author;
    list.list[x].date = tmp.date;
    list.list[x].description = tmp.description;
    list.list[x].inAuction = tmp.inAuc;
    list.save();
    res.render('paint', {
        x:list.list[x]
    });
});

server.post('/participant/:num', (req, res)=>{
    let x = req.params.num;
    let tmp = req.body;
    participants.participants[x].name = tmp.name;
    participants.participants[x].location = tmp.location;
    participants.participants[x].inAuc = tmp.inAuc;
    participants.participants[x].coord.x = tmp.x;
    participants.participants[x].coord.y = tmp.y;
    participants.save();
});

server.post('/paintings', (req, res)=>{
    let tmp = req.body;
    name = list.list.length;
    let t = new Picture();
    t.id = list.list.length;
    t.name = tmp.name;
    t.author = tmp.author;
    t.date = tmp.date;
    t.description = tmp.description;
    t.img = t.id+'.jpg';
    list.list.push(t);
    res.status(200);
    list.save();
    res.send(pug.compileFile('./views/table.pug', {paintings:list.list}));
});

server.get('/participant/:num', (req, res, next)=>{
    let _id = req.params.num;
    res.render('participant', {
        x: participants.participants[_id]
    });
});

server.get('/:num'+'.jpg', (req, res)=>{
    let x = req.params.num;
    res.sendFile('./public/image/'+list.list[x].img);
});

server.get('/settings',(req, res)=>{
    res.render('settings',{
        x: settings
    });
});

server.get('/1.mp3', (req, res)=>{
    res.status(200);
    res.sendFile(__dirname+'/public/images/'+1+'.mp3');
});

server.get('/auction', (req, res)=>{
    let tmp = list.list.filter((e)=>{
        return e.inAuction=="Yes";
    });
    settings.curLot = tmp[0];
    let fs = require('fs');
    fs.writeFile('./public/json/settings.json', JSON.stringify(settings), (err)=>{

    });
    res.render('auc', {
        participants:participants.participants,
        x:tmp[0]
    });
});

