class Settings {
    constructor(){
        this.curLot = null;
        this.curBuyer = {id:null, buyer: null, value: null};
        this.date = null;
        this.time = null;
        this.time_out = null;
        this.duration = null;
        this.pause = null;
        this.paintings = null;
        this.participants = null;
    }

    save(){
        let fs = require('fs');
        fs.writeFile('../lab3/public/json/settings.json', JSON.stringify(this), (err)=>{
            console.log(err);
        });
    }
}

let settings = new Settings();
console.log(JSON.stringify(settings));
settings = require('../json/settings')
module.exports = settings;