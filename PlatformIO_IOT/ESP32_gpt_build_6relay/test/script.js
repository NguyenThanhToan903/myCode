const output = document.getElementById('output');
const input = document.getElementById('input');
const sendBtn = document.getElementById('sendBtn');

const ws = new WebSocket('ws://' + window.location.host + '/websocket?client_num=0');

ws.onopen = function(event) {
  output.innerHTML += '<div class="message">Connected</div>';
}

ws.onmessage = function(event) {
  output.innerHTML += '<div class="message">' + event.data + '</div>';
}

ws.onclose = function(event) {
  output.innerHTML += '<div class="message">Disconnected</div>';
}

sendBtn.onclick = function() {
  const message = input.value;
  ws.send(message);
  input.value = '';
}
