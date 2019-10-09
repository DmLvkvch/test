generate_table();

function generate_table() {
    var body = document.getElementsByTagName("body")[0];
    var txt = document.createElement('h1');
    txt.innerText = "Scoreboard";
    txt.style.marginLeft = 690+"px";
    body.appendChild(txt)
    var tbl = document.createElement("table");
    tbl.style.position = "absolute";
    tbl.style.marginLeft = 700+"px";
    var tblBody = document.createElement("tbody");
    let records = JSON.parse(localStorage["tetris.records"]);
    var row = document.createElement("tr");
    var cell = document.createElement("td");
    var cellText = document.createTextNode("Username");
    cell.appendChild(cellText);
    row.appendChild(cell);
    var cell = document.createElement("td");
    var cellText = document.createTextNode("Score");
    cell.appendChild(cellText);
    row.appendChild(cell);
    tblBody.appendChild(row);
    for (var i = 0; i < records.length; i++) {
        var row = document.createElement("tr");
        for (var j = 0; j < 2; j++) {
            var cell = document.createElement("td");
            if (j == 0)
                var cellText = document.createTextNode(records[i].name);
            else
                var cellText = document.createTextNode(records[i].score);

            cell.appendChild(cellText);
            row.appendChild(cell);
        }
        tblBody.appendChild(row);
    }
    tbl.appendChild(tblBody);
    body.appendChild(tbl);
    var button = document.createElement("input");
    button.type = "button";
    button.value = "Main menu";
    button.style.position = 'absolute';
    button.style.marginLeft = 600+"px";
    button.style.marginTop = "px";
    button.onclick = () => {
        window.location.href = "main.html";
    };
    body.appendChild(button);
    tbl.setAttribute("border", "2");
}