const ffi = require("ffi-napi");
const fs = require("fs");

//Convert JSString to CString
function TEXT(text) {
    return Buffer.from(`${text}\0`, "ucs2");
}

// Import libPrueba3
const VSPlib = new ffi.Library("./VSPlib/libPrueba3", {
    "getGCPointers": [
        "void", []
    ]
});

// Call the getGCPointers function
console.log("Hello World!");

let rawdata = fs.readFileSync('./cmake-build-debug/GCPointers.json');
let student = JSON.parse(rawdata);
console.log(student);



