class Participant{
    constructor(){
        this.id = null;
        this.name = null;
        this.inAuc = 'No';
        this.location = null;
        this.coord = {x:0, y:0};
        this.networth = 100;
        this.paints = [];
    }
}

participant = new Participant();
module.exports = Participant;