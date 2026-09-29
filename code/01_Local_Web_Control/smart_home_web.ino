#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>

const char* ssid = "ESP32_Home";
const char* password = "12345678";

WebServer server(80);
DNSServer dnsServer;

#define RELAY1 23
#define RELAY2 22
#define RELAY3 21

bool relay1State = false;
bool relay2State = false;
bool relay3State = false;

void handleRoot() {
  String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>Smart Home Control</title>
<style>
*{
  margin:0;
  padding:0;
  box-sizing:border-box;
  font-family:Arial;
}

body{
  background:#0f172a;
  color:white;
  text-align:center;
  padding:20px;
}

.container{
  max-width:450px;
  margin:auto;
}

h1{
  margin-top:20px;
  margin-bottom:30px;
  font-size:28px;
}

.card{
  background:#1e293b;
  border-radius:20px;
  padding:20px;
  margin-bottom:20px;
  box-shadow:0 8px 20px rgba(0,0,0,0.3);
}

.device{
  display:flex;
  justify-content:space-between;
  align-items:center;
  font-size:20px;
}

.btn{
  border:none;
  padding:14px 24px;
  border-radius:12px;
  font-size:16px;
  cursor:pointer;
  font-weight:bold;
}

.on{
  background:#22c55e;
  color:white;
}

.off{
  background:#ef4444;
  color:white;
}
</style>
</head>
<body>

<div class="container">
<h1>Smart Home Automation</h1>
)rawliteral";

  html += "<div class='card'><div class='device'><span>Relay 1</span>";
  html += "<a href='/relay1'><button class='btn ";
  html += (relay1State ? "on'>ON" : "off'>OFF");
  html += "</button></a></div></div>";

  html += "<div class='card'><div class='device'><span>Relay 2</span>";
  html += "<a href='/relay2'><button class='btn ";
  html += (relay2State ? "on'>ON" : "off'>OFF");
  html += "</button></a></div></div>";

  html += "<div class='card'><div class='device'><span>Relay 3</span>";
  html += "<a href='/relay3'><button class='btn ";
  html += (relay3State ? "on'>ON" : "off'>OFF");
  html += "</button></a></div></div>";

  html += R"rawliteral(
</div>

</body>
</html>
)rawliteral";

  server.send(200, "text/html", html);
}

void toggleRelay1() {
  relay1State = !relay1State;
  digitalWrite(RELAY1, relay1State ? LOW : HIGH);
  handleRoot();
}

void toggleRelay2() {
  relay2State = !relay2State;
  digitalWrite(RELAY2, relay2State ? LOW : HIGH);
  handleRoot();
}

void toggleRelay3() {
  relay3State = !relay3State;
  digitalWrite(RELAY3, relay3State ? LOW : HIGH);
  handleRoot();
}

void setup() {
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);

  // Relay OFF at startup (Active LOW)
  digitalWrite(RELAY1, HIGH);
  digitalWrite(RELAY2, HIGH);
  digitalWrite(RELAY3, HIGH);

  // Start Access Point
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.println("WiFi Started");
  Serial.print("IP Address: ");
  Serial.println(myIP);

  // DNS Auto Redirect (Captive Portal)
  dnsServer.start(53, "*", myIP);

  server.on("/", handleRoot);
  server.on("/relay1", toggleRelay1);
  server.on("/relay2", toggleRelay2);
  server.on("/relay3", toggleRelay3);

  // Redirect all unknown URLs to home page
  server.onNotFound([]() {
    handleRoot();
  });

  server.begin();
  Serial.println("Web Server Started");
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
}
