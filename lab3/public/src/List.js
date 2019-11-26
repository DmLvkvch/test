class List{
    constructor(){
        this.list = [];
    }

    load(){
        this.list = require('../json/auction')
    }

    save(){
        let fs = require('fs');
        fs.writeFile('../lab3/public/json/auction.json', JSON.stringify(this.list), (err)=>{
            console.log(err);
        });
    }

    add(pic){
        pic.id = this.list.length;
        this.list.push(pic);
    }

    remove(id){
        for (let i = 0; i < this.list.length; i++) {
            if(this.list[i].id===id) {
                this.list.splice(i, 1);
                return;
            }
        }
    }
}

let list = new List();
list.load();
module.exports = list;