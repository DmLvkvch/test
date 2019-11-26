const express = require("express");
const  router = express.Router();
const pug = require('pug');
let settings = require('./public/src/settings');
let Picture = require('./public/src/Picture');
let list = require('./public/src/List');
let participants = require('./public/src/Participants');
let multer = require('multer');
const path = require("path");
let Participant = require('./public/src/Participant');

let name = "";

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
    console.log(name);
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
   console.log(JSON.stringify(participants.participants[_id]));
   res.render('participant', {
      x: participants.participants[_id]
   });
});

server.get('/:num'+'.jpg', (req, res)=>{
   let x = req.params.num;
   res.sendFile('./public/image/'+list.list[x].img);
});

server.get('/settings',(req, res)=>{
   console.log(JSON.stringify(settings));
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

module.exports = router;