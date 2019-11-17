let canvas = document.getElementById('game');//для поля тетриса
let context = canvas.getContext('2d');
let scale = 20;
context.scale(scale,scale);
context.fillStyle = "#000";
context.fillRect(0, 0, canvas.width, canvas.height);
let map = new Map();
let obj = [];
let player = new Player();
player.coord.x = 10;
player.coord.y = 18;
let enemy = new Enemy();
enemy.coord.x = 10;
enemy.coord.y = 1;
obj.push(player);
obj.push(enemy);
enemy.map = map;
player.map = map;
let over = false;

addvertWall(3,  3, 7);
addvertWall(4,  3, 7);

addvertWall(15,  3, 7);
addvertWall(16,  3, 7);

addvertWall(7,  3, 7);
addvertWall(12,  3, 7);

addvertWall(8,  10, 15);
addvertWall(11,  10, 15);

addvertWall(9,  12, 15);
addvertWall(10,  12, 15);

addhorWall(5,  8, 14);
addhorWall(12,  15, 14);

addhorWall(5,  8, 14);
addhorWall(12,  15, 14);

addvertWall(2,  10, 17);
addvertWall(17,  10, 17);

put();
repaint();
function clear() {
    for (let i = 0; i < map.map.length; i++) {
        map.map[i] = new Array(20).fill(0);
    }
}

function addvertWall(x, y, y1) {
    for(let i = y;i<y1;i++){
        let block = new Block();
        block.coord.x = x;
        block.coord.y = i;
        obj .push(block);
    }
}

function addhorWall(x, x1, y) {
    for(let i = x;i<x1;i++){
        let block = new Block();
        block.coord.x = i;
        block.coord.y = y;
        obj .push(block);
    }
}

function put() {
    clear();
    for (let i = 0; i < obj .length; i++) {
        map.map[obj[i].coord.x][obj[i].coord.y] = obj[i];
    }
}

document.addEventListener('keydown', (event)=>{
    let keyId = event.keyCode;
    let x = player.coord.x;
    let y = player.coord.y;
    if(keyId === 37){
            player.moveLeft();
    }else if (keyId === 39){
            player.moveRight();
    }
    else if (keyId === 40){
            player.moveDown();
    }
    else if (keyId === 38) {
            player.moveUp();
    }
    else if(keyId===32){
        let bul = player.fire();
        obj.push(bul);
        inteval = setInterval(f, bul.speed);
    }
    put();
    console.log(enemy.coord);
    repaint();
});

let inteval = 0;
function f() {
    if(player.onTouch(obj[obj.length-1].coord.x, obj[obj.length-1].coord.y-1)){
        clearInterval(inteval);
        obj.splice(obj.length-1, 1);
    }
    if(obj[obj.length-1].onTouch(obj[obj.length-1].coord.x, obj[obj.length-1].coord.y-1)) {
        clearInterval(inteval);
        obj.splice(obj.length-1, 1);
        put();
        repaint();
        return;
    }
    obj[obj.length-1].coord.y--;
    put();
    repaint();
}

function repaint() {
    enemy.move({x:player.coord.x, y:player.coord.y});
    map.draw(context);
    for(let i = 0;i<obj.length;i++)
        if(!(obj[i] instanceof Block))
            obj[i].draw(context);
}
