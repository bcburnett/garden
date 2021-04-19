//default html page if not in SPIFFS

// beginning of default web page
const char htmlCode[]PROGMEM = R"rawliteral(
 <!DOCTYPE HTML>
<html>

<head>
  <! define meta data>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <! define the style CSS of your page>
      <style>
        html {
          font-family: Arial;
          display: inline-block;
          text-align: center;
        }

        h1 {
          font-size: 2.9rem;
        }

        h2 {
          font-size: 2.1rem;
        }

        p {
          font-size: 1.9rem;
        }

        body {
          margin:auto;
          padding-bottom: 30px;
          text-align: center;
        }

      </style>
</head>

<body>

  <div style="width: 75%; margin:auto; text-align:center;"></div>
  <h2>ESP32 Weather Station <span id="time"></span></h2>


   
    <hr>
    <p>Soil Moisture: <span id="moisture"></span></p>

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
      json = JSON.parse(event.data);
      console.log(json);
      document.getElementById("moisture").innerHTML = json.moisture;
      if (json.reload) location.reload();
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