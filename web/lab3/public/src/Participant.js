class Participant{
    constructor(){
        this.id = null;
        this.name = null;
        this.inAuc = false;
        this.location = null;
        this.coord = {
            x:0, y:0
        }
    }
}

participant = new Participant();
module.exports = Participant;