const { SerialPort } = require('serialport')
const { ReadlineParser } = require('@serialport/parser-readline')
const prompt = require('prompt-sync')();
const parser = new ReadlineParser()
const port = new SerialPort({
    path: '/dev/ttyUSB0',
    baudRate: 9600,
})

port.on("open",open)

function open(){
  console.log("Connected")
}

const parser2 = port.pipe(new ReadlineParser({delimiter: '\r\n'}))
parser2.on("data",getdata)

function getdata(data){
  console.log(data)
}

const num = prompt('Enter number of times to blink per second:');
port.write(num)