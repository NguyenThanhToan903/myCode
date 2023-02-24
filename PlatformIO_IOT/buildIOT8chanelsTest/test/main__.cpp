/*********
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-websocket-server-arduino/
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*********/

// Import required libraries
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char *ssid = "4Cs Coffee";
const char *password = "4csxinchao";

bool ledState = 0;
const int ledPin = 2;

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

const char index_html[] PROGMEM = R"rawliteral(

    <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="icon" href="data:,">
    <style>
        html, body {
            margin: 0;
            padding: 0;
        }
        html {
            text-align: center;
        }
        body {
            font-family: sans-serif;
        }
        h1 {
            font-size: 2em;
            color: white;
        }
        h2 {
            font-size: 1.5em;
            font-weight: bold;
            color: #143642;
        }
        .topnav {
        overflow: hidden;
        background-color: #143642;
        }
        body {
            margin: 0;
        }
        .content{
            padding: 30px;
            min-width: 600px;
            margin: 0 auto;
        }
        .card{
            background-color: #F8F7F9;
            box-shadow: 2px 2px 12px 1px rgba(140,140,140,.5);
            padding-top: 10px;
            padding-bottom: 20px;

        }
        .hf-card{
            min-width: 400px;
            display: inline-block;
            text-align: unset;
        }
        .button{
            padding: 15px 50px;
            text-align: center;
            font-size: 1.5em;
            outline: none;
            border: none;
            cursor: pointer;
            color: #fff;
            background-color: #0f8b8d;
            border-radius: 5px;
            -webkit-touch-callout: none;
            -webkit-user-select: none;
            -moz-user-select: none;
            -ms-user-select: none;
            user-select: none;
            -khtml-user-select: none;
            -webkit-tap-highlight-color: rgba(0, 0, 0, 0);
        }
        .button:active{
            background-color: #0f8b8d;
            box-shadow: 2 2px #CDCDCD;
            transform: translateY(2px);
        }
        .state{
            font-size: 1.5em;
            color: #8c8c8c;
            font-weight: bold;
        }
    </style>

</head>
<body>
    <div class="topnav">
        <h1>ESP WebSocket Server</h1>
    </div>
    <div class="content">
        <div class="card">
            <div>
                <div class="hf-card">
                    <h2>Output - 1</h2>
                    <p class="state">State: <span id="state1">%STATE%</span></p>
                    <p><button id="button1" class="button">Công tắc</button></p>
                </div>
                <div class="hf-card">
                    <h2>Output - 2</h2>
                    <p class="state">State: <span id="state2">%STATE%</span></p>
                    <p><button id="button2" class="button">Công tắc</button></p>
                </div>
            </div>
            <div>
                <div class="hf-card">
                    <h2>Output - 3</h2>
                    <p class="state">State: <span id="state3">%STATE%</span></p>
                    <p><button id="button1" class="button">Công tắc</button></p>
                </div>
                <div class="hf-card">
                    <h2>Output - 4</h2>
                    <p class="state">State: <span id="state4">%STATE%</span></p>
                    <p><button id="button2" class="button">Công tắc</button></p>
                </div>
            </div>
        </div>
        
    </div>
    <script>
        var gateway = `ws://${window.location.hostname}/ws`;
        var websocket;
        function initWebSocket() {
            console.log('Trying to open websocket connection...');
            websocket = new WebSocket(gateway);
            websocket.onopen = onOpen;
            websocket.onclose = onClose;
            websocket.onmessage = onMessage;
        }

        function onOpen(event) {
            console.log('Connected opened');
        }
        function onClose(event) {
            console.log('Connection closed');
            setTimeout(initWebSocket, 2000);
        }
        function onMessage(event) {
            var state;
            if (event.data == "1"){
                state = "ON";
            }
            else{
                state = "OFF";
            }
            document.getElementById('state').innerHTML = state;
        }
        window.addEventListener('load', onLoad);
        function onLoad(event){
            initWebSocket();
            initButton();
        }
        function initButton() {
            document.getElementById('button').addEventListener('click', Toggle);
        }
        function Toggle(){
            websocket.send('toggle');
        }

    </script>
</body>
</html>
)rawliteral";

void notifyClients()
{
    ws.textAll(String(ledState));
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len)
{
    AwsFrameInfo *info = (AwsFrameInfo *)arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT)
    {
        data[len] = 0;
        if (strcmp((char *)data, "toggle") == 0)
        {
            ledState = !ledState;
            notifyClients();
        }
    }
}

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
    switch (type)
    {
    case WS_EVT_CONNECT:
        Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
        break;
    case WS_EVT_DISCONNECT:
        Serial.printf("WebSocket client #%u disconnected\n", client->id());
        break;
    case WS_EVT_DATA:
        handleWebSocketMessage(arg, data, len);
        break;
    case WS_EVT_PONG:
    case WS_EVT_ERROR:
        break;
    }
}

void initWebSocket()
{
    ws.onEvent(onEvent);
    server.addHandler(&ws);
}

String processor(const String &var)
{
    Serial.println(var);
    if (var == "STATE")
    {
        if (ledState)
        {
            return "ON";
        }
        else
        {
            return "OFF";
        }
    }
    return String();
}

void setup()
{
    // Serial port for debugging purposes
    Serial.begin(115200);

    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }

    // Print ESP Local IP Address
    Serial.println(WiFi.localIP());

    initWebSocket();

    // Route for root / web page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
              { request->send_P(200, "text/html", index_html, processor); });

    // Start server
    server.begin();
}

void loop()
{
    ws.cleanupClients();
    digitalWrite(ledPin, ledState);
}
