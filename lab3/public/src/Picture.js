class Picture{
    constructor(){
        this.id = null;
        this.name = null;
        this.author = null;
        this.date = null;
        this.description = null;
        this.min = 0;
        this.max = 999999;
        this.step = 0;
        this.inAuction = "No";
        this.img = null;
        this.sold = false;
        this.owner = null;
    }
}

let picture = new Picture();
module.exports = Picture;