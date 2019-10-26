const express = require("express");
const server = express();
const bodyParser = require('body-parser');
const cookieParser = require('cookie-parser');
const routes = require("./routes");
const fs = require("fs");
const https = require("https");
const multer = require('multer')
var keys = {
    key: fs.readFileSync('./ssl/ex.key'),
    cert: fs.readFileSync('./ssl/ex.csr'),
};
server.use(express.static('./public/images'));
server.use(express.static('./public/src'));
server.use(express.static('./public/less'));
server.use(cookieParser());
server.use(bodyParser.json());
server.use(bodyParser.urlencoded({extended:true}));
server.use('/', routes);
server.set('view engine', 'pug');
server.set('views','./views');

let app = https.createServer(keys, server).listen(3000, function(){

});