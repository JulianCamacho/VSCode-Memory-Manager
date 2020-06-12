// Poner nombre de usuario
// Guardar la conexión como JSON
// 

const express = require('express');
const path = require('path')
const fs = require('fs')
const { v4: uuidv4 } = require('uuid');

const app = express();

app.use(express.json())
app.use(express.static(path.join(__dirname, "public")));

// Return index.html for the comunication with server
app.get('/', (req, res) => {
    console.log("Got user request")
    res.sendFile(path.join(__dirname, "public", "index.html"));
});

//Receibe the info of vspointers, get all their atributes, save them into server
//req: Info of vspointers.
app.post('/api', (req, res) => {
    let _serverVSPointers = {};
    CANGETVSPOINTER = false; // Cant get vs pointers unti log into server
    for (let i = 0; i < req.body.generalList.length; i++) {
        let _uuid = uuidv4();
        _serverVSPointers[_uuid] = [req.body.typeList[i], req.body.valueList[i]];
    }
    serverVSPointers = _serverVSPointers;
    res.status(200);
});

//Server returns the id and info of the pointers in json format
//
app.get('/getvspointers', (req, res) => {
    console.log("Trying to get vspointers info")
    let _json = {};
    if (CANGETVSPOINTER) {
        _json["message"] = JSON.stringify(serverVSPointers);
    } else {
        _json["message"] = "You must log in";
    }
    console.log("enviar: " + _json);
    //
    res.send(_json);
})

//To log into the server, confirm the password, ip and port
//req: contains password, ip and port to listen
//res: Nothing

app.post('/log', (req, res) => {
    console.log("Trying to enter server!");
    console.log(req.body)

    if ((req.body.password == SERVERPASSWORD) &&
        (req.body.ip == SERVERIP) &&
        (req.body.port == SERVERPORT)) {
        console.log("Got access to server!")
        1
        2

        var today = new Date();
        var date = today.getFullYear() + '-' + (today.getMonth() + 1) + '-' + today.getDate();

        req.body["time"] = date;
        //Save the conection in json format
        fs.writeFile("conections/" + req.body.username + ".json", JSON.stringify(req.body), (err) => {
            if (err) throw err;
            console.log("saved conection as json")
        });
        CANGETVSPOINTER = true;
    }

})

app.get('/getlog', (req, res) => {
    console.log("Trying to get log info")
    var _json = [];

    fs.readdirSync('./conections').forEach(file => {
        console.log(file);
        fs.readFile('./conections/' + file, 'utf8', (err, data) => {
            if (err) throw err;
            console.log(data);
            _json.push(data);
        })

        console.log("Termina con: " + file)
    });

    console.log("Envia get log: " + _json)
    res.send(_json);

})


//**************** Constant of server **************************/

const SERVERPORT = 5000; //Deploy the port in enviroment port, must
const SERVERIP = '121.12.250.1'; // Uses this ip
const SERVERPASSWORD = '0cbefbc1ef0639ba18485104440f399c'; //MyServer in MD5

//****** Vspointers that were saved ******/
var serverVSPointers;
var CANGETVSPOINTER = false;

app.listen(SERVERPORT, () => console.log(`Server started ib port ${SERVERPORT}`));