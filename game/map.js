class  Map {
    constructor(){
        this.map = new Array(20);
        for (let i = 0; i < this.map.length; i++) {
            this.map[i] = new Array(20).fill(0);
        }
    }

    draw(ctx){
        let img;
        img = document.getElementById('wall');
        for (let i = 0; i < this.map.length; i++) {
            for (let j = 0; j < this.map[i].length; j++) {
                 if(this.map[i][j] instanceof Block) {
                    ctx.drawImage(img, i, j, 1, 1)
                }else if(this.map[i][j]===0){
                    ctx.fillStyle = '#000';
                    ctx.fillRect(i, j, 1, 1);
                }
            }
        }
    }
}

