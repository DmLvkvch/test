let canvas = document.getElementById('tetris');//для поля тетриса
let context = canvas.getContext('2d');
context.scale(20,20);
context.fillStyle = "#FFF";
context.fillRect(0, 0, canvas.width, canvas.height);
let interval = setInterval(function () {
    down();
    repaint();
}, 1000);

Field = new Array(10);
for(let i = 0;i<20;i++){
    Field[i] = new Array(10).fill(0);
}

const gamer = {
    location: {x: 0, y: 0},
    center: {x: 0, y: 0},
    tetramino: null,
    score: 0,
    name: null,
    figureId: 0,
};

const colors = [
    null,
    '#D9B5FD',
    '#BAF1FC',
    '#FEFEAA',
    '#B8FFB3',
    '#FDBED1',
    '#FFE7BD',
    '#F8CFBE',
];

function createFigure(tmp) {
    if (tmp === 1) {
        return 	[
            [0, 1, 0],
            [1, 1, 1],
            [0, 0, 0]
        ]
    } else if ( tmp === 2) {
        return [
            [2, 2],
            [2, 2],
        ]
    } else if ( tmp === 3) {
        return [
            [3, 3, 3],
            [3, 0, 0],
            [0, 0, 0]]
    } else if ( tmp === 4) {
        return [
            [4, 0, 0],
            [4, 4, 4],
            [0, 0, 0]
        ]
    }else if (tmp === 5) {
        return [
            [5, 5, 0],
            [0, 5, 5],
            [0, 0, 0]
        ];
    } else if (tmp === 6) {
        return [
            [0, 6, 6],
            [6, 6, 0],
            [0, 0, 0]
        ]
    } else if (tmp === 7) {
        return [
            [0, 7, 0, 0],
            [0, 7, 0, 0],
            [0, 7, 0, 0],
            [0, 7, 0, 0]
        ]
    }
    else if (tmp === 8) {
        return [
            [7, 7, 0, 7],
            [7, 0, 0, 7],
            [7, 0, 0, 7],
            [7, 7, 7, 7]
        ]
    }
}

function drawFigure(tetramino, location) {
    tetramino.forEach((row,y)=> {
        row.forEach((val,x) => {
            if (val !== 0) {
                context.fillStyle = colors[val];
                context.fillRect(x + location.x, y + location.y, 1, 1);
            }
        });
    });
}

let nextFigure_ = document.getElementById('nextFigure');
let figure_ = nextFigure_.getContext('2d');
figure_.scale(40, 40);

function drawNextFigure(tetramino_) {
    figure_.fillStyle = "#FFF";
    figure_.fillRect(0, 0, nextFigure_.width, nextFigure_.height);//для поля 'след фигуура'
    tetramino_.forEach((row,y)=> {
        row.forEach((val,x) => {
            if (val !== 0) {
                figure_.fillStyle = colors[val];
                figure_.fillRect(x+1.2, y, 1, 1);
            }
        });
    });
}
let lose = false;
function addToField(gamer){
    gamer.tetramino.forEach((row, y)=>{
               row.forEach((val, x)=>{
                   if(val!==0)
                    Field[y+gamer.location.y][x+gamer.location.x] = val
               });
    });
    if (isOutOfBounds(gamer.location.x, gamer.location.y-1)) {
        lose = true;
    }
}

function rotate (gamer) {
    let x = gamer.tetramino.length;
    if(x===3){
        let tmp = gamer.tetramino[0][0];
        gamer.tetramino[0][0] = gamer.tetramino[2][0];
        gamer.tetramino[2][0] = gamer.tetramino[2][2];
        gamer.tetramino[2][2] = gamer.tetramino[0][2];
        gamer.tetramino[0][2] = tmp;
        tmp = gamer.tetramino[0][1];
        gamer.tetramino[0][1] = gamer.tetramino[1][0];
        gamer.tetramino[1][0] = gamer.tetramino[2][1];
        gamer.tetramino[2][1] = gamer.tetramino[1][2];
        gamer.tetramino[1][2] = tmp;
    } else if (x === 4) {
        let tmp = gamer.tetramino[0][1];
        gamer.tetramino[0][1] = gamer.tetramino[1][0];
        gamer.tetramino[1][0] = tmp;
        tmp = gamer.tetramino[2][1];
        gamer.tetramino[2][1] = gamer.tetramino[1][2];
        gamer.tetramino[1][2] = tmp;
        tmp = gamer.tetramino[3][1];
        gamer.tetramino[3][1] = gamer.tetramino[1][3];
        gamer.tetramino[1][3] = tmp;
    }
}

let n = next();
let next_f = createFigure(n);
function init() {
    gamer.tetramino = createFigure(n);
    gamer.location = {x: (Field[0].length / 2) - Math.floor(gamer.tetramino[1].length / 2), y: 0};
    n = next();
    next_f = createFigure(n);
    drawNextFigure(next_f);
}

function nextStep() {
    init();
    clearInterval(interval);
    if(isOver() || lose){
        addRecord();
        clearInterval(interval);
        document.getElementById('score').innerText = gamer.score;
        window.location.href = "end.html";
        return;
    }
    drawFigure(gamer.tetramino, gamer.location);
    interval = setInterval(function () {
        down();
        repaint();
    }, V);
}

function start() {
    init();
    document.getElementById('speed').innerText = V;
    gamer.name = localStorage.getItem('tetris.username');
    document.getElementById('outputName').innerText = gamer.name;
    document.getElementById('score').innerText = gamer.score;
    drawFigure(gamer.tetramino, gamer.location);
}

function next(){
    return  Math.floor(Math.random()*7)+1
}

function checkCollision(x, y) {
    for(let i = 0; i < gamer.tetramino.length; ++i) {
        for(let j = 0; j < gamer.tetramino[i].length; ++j) {
            if (gamer.tetramino[i][j]) {
                if (Field[y-gamer.center.y+i][x-gamer.center.x+j]) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

function isOutOfBounds(x, y) {
    for(let i = 0; i < gamer.tetramino.length; ++i) {
        for(let j = 0; j < gamer.tetramino[i].length; ++j) {
            if (gamer.tetramino[i][j]) {
                if (x-gamer.center.x+j >= 10) {
                    return true;
                }
                if (y-gamer.center.y+i >= 20) {
                    return true;
                }
                if (x-gamer.center.x+j < 0) {
                    return true;
                }
                if (y-gamer.center.y+i < 0) {
                    return true;
                }
            }
        }
    }
    return false;
}

function canRotate() {
    rotate(gamer);
    if (!isOutOfBounds(gamer.location.x, gamer.location.y) && !checkCollision(gamer.location.x, gamer.location.y))
        return true;
    rotate(gamer);
    rotate(gamer);
    rotate(gamer);
    return false;
}

function isOver() {
    return (checkCollision(Math.floor(Field[0].length / 2) - Math.floor(gamer.tetramino[1].length / 2), 0))
}

function checkLine(array) {
    for (let i = 0; i < array.length; i++) {
        if(array[i]===0)
            return false;
    }
    return true;
}


function LowerDown(index) {
    for (let j = index; j > 0; j--) {
        for (let i = 0; i < Field[0].length; i++) {
                Field[j][i] = Field[j - 1][i]
            }
        }
}

function clearLine() {
    for (let i = 0; i < Field.length; i++) {
        if(checkLine(Field[i])) {
            gamer.score++;
            speed();
            document.getElementById('score').innerText = gamer.score;
            for (let j = 0; j < Field[i].length; j++) {
                Field[i][j] = 0;
            }
            LowerDown(i)
        }
    }
    
}

function down(){
    if (!isOutOfBounds(gamer.location.x, gamer.location.y+1) && !checkCollision(gamer.location.x, gamer.location.y+1)) {
        gamer.location.y += 1;
    }
    else{
        addToField(gamer);
        clearLine();
        repaint();
        nextStep();
    }
}

function right(){
    if (!isOutOfBounds(gamer.location.x+1, gamer.location.y) && !checkCollision(gamer.location.x+1, gamer.location.y))
        gamer.location.x+=1;
}

function left(){
    if (!isOutOfBounds(gamer.location.x-1, gamer.location.y) && !checkCollision(gamer.location.x-1, gamer.location.y))
        gamer.location.x-=1;
}

function repaint(){
    if(isOver() || lose)
        return;
    context.fillStyle = '#fff';
    context.fillRect(0, 0, canvas.width, canvas.height);
    drawFigure(Field, {x: 0, y: 0});
    drawFigure(gamer.tetramino, gamer.location);
}
let V = 1000;
function speed(){
    if(gamer.score>=30){
        clearInterval(interval);
        interval = setInterval(function () {
            down();
            repaint();
        }, 50);
        V = 50;
        document.getElementById('speed').innerText = V;
        return;
    }

    if(gamer.score>=25){
        clearInterval(interval);
        interval = setInterval(function () {
            down();
            repaint();
        }, 100);
        V = 100;
        document.getElementById('speed').innerText = V;
        return;
    }

    if(gamer.score>=20){
        clearInterval(interval);
        interval = setInterval(function () {
            down();
            repaint();
        }, 200);
        V = 200;
        document.getElementById('speed').innerText = V;
        return;
    }
    if(gamer.score>=15){
        clearInterval(interval);
        interval = setInterval(function () {
            down();
            repaint();
        }, 400);
        V = 400;
        document.getElementById('speed').innerText = V;
        return;
    }
    if(gamer.score>=10){
        clearInterval(interval);
        interval = setInterval(function () {
            down();
            repaint();
        }, 600);
        V = 600;
        document.getElementById('speed').innerText = V;
        return;
    }
    if(gamer.score>=5){
        clearInterval(interval);
        interval = setInterval(function () {
            down();
            repaint();
        }, 800);
        V = 800;
        document.getElementById('speed').innerText = V;
        return;
    }
    document.getElementById('speed').innerText = V;
    console.log(interval)
}

document.addEventListener('keydown', (event)=>{
    let keyId = event.keyCode;
    if(keyId === 37){
        left();
    }else if (keyId === 39){
        right();
    }

    else if (keyId === 40){
        down();
    }
    else if (keyId === 38){
        if(canRotate()){
            rotate(gamer);
            rotate(gamer);
        }

    }else if(keyId === 32){
        while (!isOutOfBounds(gamer.location.x, gamer.location.y+1) && !checkCollision(gamer.location.x, gamer.location.y+1))
            down();
    }
    repaint();
});

function contains(array, x) {
    for (let i = 0; i < array.length; i++) {
        if(array[i].name==x)
            return true;
    }
    return false;
}

function addRecord() {
    let username = localStorage.getItem("tetris.username");
    let records = localStorage.getItem("tetris.records");
    //console.log(username)
    if (records) {
        records = JSON.parse(records);
    }	 else {
        records = [];
        let obj = {
            score: gamer.score,
            name: username
        };
        records[0] = obj;
        localStorage.setItem("tetris.records", JSON.stringify(records));
        return;
    }

    if(!contains(records, username)) {
        let obj = {
            score: gamer.score,
            name: username
        };
        records.push(obj);
    }

    for (let i = 0; i < records.length; i++) {
        if(records[i].name===gamer.name){
            records[i].score = gamer.score;
        }
    }

    records.sort(function (a, b) {
        return b.score - a.score;
    });
    /*
    // Searching for record's place:
    let row = 0;
    for(; row < records.length; ++row) {
        if (records[row].score < gamer.score)
            break;
    }

    // Exit if it's not a record:
    if(row > 9)
        return;

    // Moving rows
    for(let i = records.length-1; i > row; --i) {
        records[i].score=records[i-1].score;
        records[i].name=records[i-1].name;
    }

    let obj = {
        score: gamer.score,
        name: gamer.name
    };
    records[row] = obj;

     */
    localStorage.setItem("tetris.records", JSON.stringify(records));
}

start();