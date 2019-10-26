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

router.get('/',(req, res, next)=>{

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

router.delete('/paint/:num', (req, res)=>{
   let x = req.params.num;
   list.list.splice(x, 1);
   for(let i = x;i<list.list.length;i++){
      list.list[i].id--;
   }
   res.status(200);
   res.send("/paintings");
   list.save()
});

router.post('/image/:num', (req, res)=>{
   let x = req.params.num;
   upload(req, res, err=>{
   });
   res.status(200);
   res.sendFile(__dirname+'/public/images/'+x+'.jpg');
});

router.put('/paint/:num', (req, res)=>{
    let x1 =req.params.num;
    name = x1;
    upload(req, res, err=>{
    });
    res.status(200);
    res.end(pug.compileFile('./views/img.pug')({x:list.list[x1]}));
});

router.post('/participants', (req, res)=>{
   let tmp = req.body;
   let x = new Participant();
   x.id = participants.participants.length;
   x.name = tmp.name;
   x.inAuc = "Yes";
   x.location = tmp.location;
   x.coord.x = tmp.x;
   x.coord.y = tmp.y;
   participants.participants.push(x);
   participants.save();
   res.status(200);
   res.send(pug.compileFile('./views/participants.pug')({participants:participants.participants}));
});

router.post('/', (req, res)=>{
   let tmp = req.body;
   settings.date = tmp.date;
   settings.time = tmp.time;
   settings.time_out = tmp.out;
   settings.duration = tmp.duration;
   settings.pause = tmp.pause;
   let fs = require('fs');
   fs.writeFile('./public/json/settings.json', JSON.stringify(settings), (err)=>{
      console.log(err);
   });
});

router.post('/image',(req, res)=>{
   upload(req, res, err=>{
       res.json()
   });
});

router.get('/paintings', (req, res, next)=>{
   res.render('paintings', {
      paintings:list.list
   });
});

router.get('/paint/:num', (req, res, next)=>{
   let _id = req.params.num;
   list.list[_id].img = _id+'.jpg';
   res.render('paint', {
      x:list.list[_id]
   });
});

router.get('/participants', (req, res, next)=>{
   res.render('participants', {
      participants: participants.participants
   });
});

router.post('/paint/:num', (req, res, next)=>{
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

router.post('/participant/:num', (req, res)=>{
  let x = req.params.num;
  let tmp = req.body;
  participants.participants[x].name = tmp.name;
  participants.participants[x].location = tmp.location;
  participants.participants[x].inAuc = tmp.inAuc;
  participants.participants[x].coord.x = tmp.x;
  participants.participants[x].coord.y = tmp.y;
  participants.save();
});

router.post('/paintings', (req, res)=>{
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

router.get('/participant/:num', (req, res, next)=>{
   let _id = req.params.num;
   res.render('participant', {
      x: participants.participants[_id]
   });
});

router.get('/:num'+'.jpg', (req, res)=>{
   let x = req.params.num;
   res.sendFile('./public/image/'+list.list[x].img);
});

router.get('/settings',(req, res)=>{
   res.render('settings',{
      x: settings
   });
});

module.exports = router;