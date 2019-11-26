let socket = io.connect('http://localhost:3000');
let start;
let time = 0;
let isStarted = false;
let interval = 0;
$(function () {
    $('form').submit(function(){
            /*
            if(isStarted==false) {
                alert('Auction is not started');
                $('#m').val("");
                return false;
            }
            */
            socket.emit('chat message', $('#m').val());
            $('#m').val('');
            return false;
    });

    $('#start').on('click', function (e) {
        isStarted = true;
        start = new Date();
        let m = 0;
        time = 0;
        interval = setInterval(function () {
            time++;
            if(Math.floor((new Date - start)/1000)%60===0)
                m++;
            let str = m+" minutes "+Math.floor((new Date - start)/1000)%60+" seconds";
            socket.emit('time', str);
            socket.emit('end', time);
        }, 1000);
        return false;
    });

    socket.on('tmp', function (e) {
       alert('WRONG ID');
        let username = prompt('Please tell me your id');
        socket.emit('username', username);
    });

    socket.on('end', function (msg) {
        msg = parseInt(msg);
            let m = Math.floor(msg / 60);
            let sec = msg % 60;
            msg = `${m} minutes ${sec} seconds`;
            $('.end').text(msg);
    });

    socket.on('timer', function (msg) {
        $(".time").text(msg);
    });

    socket.on('chat message', function(msg){
        console.log(msg);
        if(msg=='ERROR4'){
            alert("Not enough money")
        }
        if(msg=='ERROR1') {
            alert("WRONG BET")
        }
        else {
            $('#messages').append($('<li>').text(msg));
            let audio = new Audio(); // Создаём новый элемент Audio
            audio.src = 'http://localhost:3000/1.mp3'; // Указываем путь к звуку "клика"
            audio.autoplay = true; // Автоматически запускаем
            $('.cur').text('Current bet:' + msg);
        }
    });

    socket.on('online', function(username) {
        console.log(username)
        $('#messages').append($('<li>').text(username+' joined to chat'));
    });

    socket.on('aucend', function (msg) {
        isStarted = false;
       clearInterval(interval);
        $(".time").text("");
        $(".end").text("");
        alert(msg+" won! Grats");
    });
});

// ask username
if(window.location.href == 'http://localhost:3000/') {
    let username = prompt('Please tell me your id');
    while(window.location.href == 'http://localhost:3000/' && username!=-1){
        alert("WRONG ID, TRY AGAIN")
        username = prompt('Please tell me your id');
    }
    socket.emit('username', username);
}

if(window.location.href == 'http://localhost:3000/auction'){
    let username = prompt('Please tell me your id');
    socket.emit('username', username);
}