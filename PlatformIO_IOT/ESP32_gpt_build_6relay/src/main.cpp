#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Tên mạng WiFi và mật khẩu
const char *ssid = "NVUICAFE-ESPORT";
const char *password = "nvuicafe";

// Trang web
const char *index_html = R"rawliteral(
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8">
    <title>WebSocket Test</title>
    <link rel="stylesheet" href="/style.css">
  </head>
  <body>
    <h1>WebSocket Test</h1>
    <div id="output"></div>
    <input type="text" id="input" placeholder="Enter message">
    <button onclick="sendMessage()">Send</button>
  </body>
  <script src="/main.js"></script>
</html>
)rawliteral";

const char *style_css = R"rawliteral(
/* CSS */
)rawliteral";

const char *main_js = R"rawliteral(
// JavaScript
var webSocket;

function initWebSocket() {
  webSocket = new WebSocket('ws://' + window.location.hostname + ':81/websocket?client_num=0');
  webSocket.onopen = function(event) {
    console.log('WebSocket opened:', event);
  };
  webSocket.onclose = function(event) {
    console.log('WebSocket closed:', event);
  };
  webSocket.onerror = function(event) {
    console.log('WebSocket error:', event);
  };
  webSocket.onmessage = function(event) {
    console.log('WebSocket message received:', event);
    var output = document.getElementById('output');
    output.innerHTML += '<p>' + event.data + '</p>';
  };
}

function sendMessage() {
  var input = document.getElementById('input');
  var message = input.value;
  webSocket.send(message);
  input.value = '';
}

initWebSocket();
)rawliteral";

// Khởi tạo ESPAsyncWebServer
AsyncWebServer server(80);

// Khởi tạo WebSocket
AsyncWebSocket ws("/websocket");

// Hàm xử lý kết nối WebSocket
void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
  if (type == WS_EVT_CONNECT)
  {
    Serial.println("Client connected");
  }
  else if (type == WS_EVT_DISCONNECT)
  {
    Serial.println("Client disconnected");
  }
  else if (type == WS_EVT_DATA)
  {
    Serial.printf("Data received: %s\n", data);
    // Gửi dữ liệu trả về cho client
    client->text("Server received your message: " + String((char *)data));
  }
}

void setup()
{
  // Kết nối WiFi
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println(WiFi.localIP());

  Serial.println("WiFi connected");

  // Cấu hình đường dẫn và callback cho các trang web
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", index_html); });
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/css", style_css); });
  server.on("/main.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "application/javascript", main_js); });

  // Kết nối WebSocket và thiết lập callback
  ws.onEvent(onWebSocketEvent);
  server.addHandler(&ws);

  // Khởi động server
  server.begin();
}

void loop()
{
}