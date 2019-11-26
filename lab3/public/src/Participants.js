class Participants{
    constructor(){
        this.participants = [];
    }

    load(){
        this.participants = require('../json/parts')
    }

    save(){
        let fs = require('fs');
        fs.writeFile('../lab3/public/json/parts.json', JSON.stringify(this.participants), (err)=>{
            console.log(err);
        });
    }
}

let participants = new Participants();
participants.load();
module.exports = participants;