const assert     = require('assert');
let settings = require('../public/src/settings');
let Picture = require('../public/src/Picture');
let list = require('../public/src/List');
let participants = require('../public/src/Participants');

describe("tests", function() {
    it('date', function() {
        settings.date = "1.1.1111";
        assert.equal(settings.date, "1.1.1111")
    });
    it('pic', function() {
        let tmp = new Picture();
        tmp.name = "DIMA";
        assert.equal(tmp.name,  "DIMA");
    });
    it('Deleting src', function() {
        let tmp = new Picture();
        tmp.img= "1.jpg";
        assert.equal(tmp.img, "1.jpg");
    });
});