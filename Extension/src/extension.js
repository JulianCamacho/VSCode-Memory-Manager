"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
const vscode = require("vscode");
// const ffi = require("ffi-napi");
const fs = require("fs");
const fetch = require("node-fetch");
const opn = require("opn");
// // Import libPrueba3
// const VSPlib = new ffi.Library("./VSPlib/libPrueba3", {
//     "getGCPointers": [
//         "void", []
//     ]
// });

let postUrl = "http://localhost:5000/api";
let browserUrl = "http://localhost:5000/";

let folderPath = vscode.workspace.rootPath; // get the open folder path
let rawdata = fs.readFileSync(folderPath + '/cmake-build-debug/GCPointers.json');
var vspointers = JSON.parse(rawdata);
// this method is called when your extension is activated
// your extension is activated the very first time the command is executed
function activate(context) {
    //var x =getGCPointers();
    // Use the console to output diagnostic information (console.log) and errors (console.error)
    // This line of code will only be executed once when your extension is activated
    console.log('Congratulations, your extension "cat-coding" is now active!');
    // The command has been defined in the package.json file
    // Now provide the implementation of the command with registerCommand
    // The commandId parameter must match the command field in package.json
    let disposable = vscode.commands.registerCommand('catCoding.start', () => {
        // The code you place here will be executed every time your command is executed
        const panel = vscode.window.createWebviewPanel('catCoding', // Identifies the type of the webview. Used internally
            'Cat Coding', // Title of the panel displayed to the user
            vscode.ViewColumn.One, // Editor column to show the new webview panel in.
            {
                // Enable scripts in the webview
                enableScripts: true
            });
        vscode.window.showInformationMessage('Hello World from cat-coding!');
        const updateWebview = () => {
            readJson();
            panel.webview.html = getWebviewContent();
        };
        // Set initial content
        updateWebview();
        // And schedule updates to the content every second
        setInterval(updateWebview, 2000);
    });
    context.subscriptions.push(disposable);
    let remote = vscode.commands.registerCommand('RemoteMemory.start', () => {
        vscode.window.showInformationMessage('Using remote memory, new!');

        const options = {
            method: "POST",
            headers: {
                'Content-Type': 'application/json'
            },
            body: JSON.stringify(vspointers),

        }

        fetch(postUrl, options)
            .then(function(response) {
                return response.json();
            })
            .then(function(myJson) {
                console.log(myJson);
            });

        opn(browserUrl);

    });

    context.subscriptions.push(remote);
}
exports.activate = activate;

function readJson() {
    let rawdata = fs.readFileSync(folderPath + '/cmake-build-debug/GCPointers.json');
    vspointers = JSON.parse(rawdata);
}

function generateTable() {
    var texto = `var tb1 = document.getElementById("myTable");`;

    for (var i = 0; i < vspointers.generalList.length; i++) {
        texto = texto +
            `
		var row = tb1.insertRow();
		var cell1 = row.insertCell();
		var cell2 = row.insertCell();
		var cell3 = row.insertCell();
		var cell4 = row.insertCell();
		var cell5 = row.insertCell();
		var cell6 = row.insertCell();
		cell1.innerHTML = ` + JSON.stringify(vspointers.addressList[i]) + `;
		cell2.innerHTML = ` + JSON.stringify(vspointers.idList[i]) + `;
		cell3.innerHTML = ` + JSON.stringify(vspointers.objNo[i]) + `;
		cell4.innerHTML = ` + JSON.stringify(vspointers.refCountList[i]) + `;
		cell5.innerHTML = ` + JSON.stringify(vspointers.typeList[i]) + `;
		cell6.innerHTML = ` + JSON.stringify(vspointers.valueList[i]) + `;
		`;
    }

    return texto;
}
// this method is called when your extension is deactivated
function deactivate() {}
exports.deactivate = deactivate;

function getWebviewContent() {
    return `<!DOCTYPE html>
	<html lang="en">
	<head>
		<meta charset="UTF-8">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<title>VSPointer visualizer</title>

	</head>

	<style type = "text/css">

		table,th,td {
			border: 1px solid White;
			border-collapse: collapse;
		}

		th, td {
			padding: 15px;
		}

	</style>

	<body>

		<h1 id = "text">VSPointer Manager</h1>

		<table id="myTable">
		  <tr>
			  <th>Address</th>
			  <th>ID</th> 
			  <th>ObjNo</th>
			  <th>RefCount</th>
			  <th>Type</th>
			  <th>Value</th>
		  </tr>
		  </table>

		<script>

			` + generateTable() + `

		</script>
	
	</body>
	</html>`;
}
//# sourceMappingURL=extension.js.map