/*
* Garden sensor sketch
* File: defaulthtml.h
* Author: Brian C. Burnett
* GitHub repo: https://github.com/bcburnett/garden
* Directory: https://github.com/bcburnett/garden/tree/master/garden
* Questions: https://github.com/bcburnett/garden/discussions/1
* 
* 
* This application is in the Public Domain.
* All information is provided in good faith, however I make no representation 
* or warranty of any kind, express or implied, regarding the accuracy, adequacy, 
* validity, reliability, availability or completeness of this application.
 */
 
#pragma once
//default html page if not in SPIFFS

// beginning of default web page
const char htmlCode[]PROGMEM = R"rawliteral(
 <!DOCTYPE HTML>
<html>

<head>
  <! define meta data>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <! define the style CSS of your page>
     
</head>

<body>



    <input type='file' name='upload' id='upload' value=''><span id="percent"></span>
  </div>
  <script>
    var gateway = `ws://${window.location.hostname}/ws`;
    var websocket;
    var state = {};
    var json = {};

    window.addEventListener('load', onLoad);

    function initWebSocket() {
      console.log('Trying to open a WebSocket connection...');
      websocket = new WebSocket(gateway);
      websocket.onopen = onOpen;
      websocket.onclose = onClose;
      websocket.onmessage = onMessage;
    }

    function onOpen(event) {
      console.log('Connection opened');
    }

    function onClose(event) {
      console.log('Connection closed');
      setTimeout(initWebSocket, 2000);
    }

    function toFixed(num, fixed) {
      var re = new RegExp('^-?\\d+(?:\.\\d{0,' + (fixed || -1) + '})?');
      return num.toString().match(re)[0];
    }

    function onMessage(event) {

    }

    // on page load
    function onLoad(event) {
      initWebSocket();
      document.getElementById("upload").addEventListener("change", (e) => processFile(e));
    }

    function processFile(e) {
      const reader = new FileReader();
      reader.readAsText(e.path[0].files[0]);
      var myfilename = e.path[0].files[0].name;

      reader.onload = (e) => {
        var myfile = e.target.result;
        var myarray = myfile.split('');
        var mylength = myfile.length;
        i = 0;
        k = 1;
        var sendArray = [];
        sendArray[0] = ("upld:" + myfilename);

        function getChunk() {
          var sendstring = '';
          for (var j = 0; j < 512; j++) {
            if (i < mylength) {
              sendstring += myarray[i];
            }
            i++
          }
          return sendstring;
        }

        function loopThroughSplittedText(splittedText) {
          splittedText.forEach(function (text, i) {
            setTimeout(function () {
              sendMessage(text, i);
            }, i * 500)
          })
        }

        while (i < mylength) {

          sendArray[k] = ("file:" + getChunk());
          k++;
        }
        sendArray[k] = ("comp");
        sendstring = '';
        loopThroughSplittedText(sendArray);
      };
    }

    function sendMessage(data, index) {
      if (index) var percent = index / k * 100;
      if (data.substring(0, 4) == 'file') document.getElementById('percent').innerHTML = percent + ' %';
      if (data.substring(0, 4) == 'comp') {
        document.getElementById('percent').innerHTML = "completed";
        setTimeout(() => {
          sendMessage("reload");
        }, 2000);
      }
      websocket.send(data);
    }
      function doTime() {
        document.getElementById('time').innerHTML = new Date().toLocaleString();
      }
      setInterval(doTime, 1000);

  </script>
</body>

</html>
)rawliteral";

// end of default web page
