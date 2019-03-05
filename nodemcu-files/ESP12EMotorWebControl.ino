/*
    This sketch demonstrates how to set up a simple HTTP-like server.
    The server will set a GPIO pin depending on the request
      http://server_ip/gpio/0 will set the GPIO2 low,
      http://server_ip/gpio/1 will set the GPIO2 high
    server_ip is the IP address of the ESP8266 module, will be
    printed to Serial when the module is connected.
*/

#include <ESP8266WiFi.h>

const char* ssid = "Tobias Mobil";
const char* password = "tobiasgrundtvig";

int PWMA = 5;
int PWMB = 4;
int DA = 0;
int DB = 2;

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DA, OUTPUT);
  pinMode(DB, OUTPUT);

  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Wait until the client sends some data
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  // Match the request
  if (req.indexOf("/A/break") != -1 ||
      req.indexOf("/A/fwd/0") != -1 ||
      req.indexOf("/A/bwd/0") != -1)
  {
    analogWrite(PWMA, 0);
  }
  else if (req.indexOf("/A/fwd/1") != -1)
  {
    digitalWrite(DA, LOW);
    analogWrite(PWMA, 255);
  }
  else if (req.indexOf("/A/fwd/2") != -1)
  {
    digitalWrite(DA, LOW);
    analogWrite(PWMA, 383);
  }
  else if (req.indexOf("/A/fwd/3") != -1)
  {
    digitalWrite(DA, LOW);
    analogWrite(PWMA, 511);
  }
  else if (req.indexOf("/A/fwd/4") != -1)
  {
    digitalWrite(DA, LOW);
    analogWrite(PWMA, 639);
  }
  else if (req.indexOf("/A/fwd/5") != -1)
  {
    digitalWrite(DA, LOW);
    analogWrite(PWMA, 767);
  }
  else if (req.indexOf("/A/fwd/6") != -1)
  {
    digitalWrite(DA, LOW);
    analogWrite(PWMA, 895);
  }
  else if (req.indexOf("/A/fwd/7") != -1)
  {
    digitalWrite(DA, LOW);
    analogWrite(PWMA, 1023);
  }
  else if (req.indexOf("/A/bwd/1") != -1)
  {
    digitalWrite(DA, HIGH);
    analogWrite(PWMA, 255);
  }
  else if (req.indexOf("/A/bwd/2") != -1)
  {
    digitalWrite(DA, HIGH);
    analogWrite(PWMA, 383);
  }
  else if (req.indexOf("/A/bwd/3") != -1)
  {
    digitalWrite(DA, HIGH);
    analogWrite(PWMA, 511);
  }
  else if (req.indexOf("/A/bwd/4") != -1)
  {
    digitalWrite(DA, HIGH);
    analogWrite(PWMA, 639);
  }
  else if (req.indexOf("/A/bwd/5") != -1)
  {
    digitalWrite(DA, HIGH);
    analogWrite(PWMA, 767);
  }
  else if (req.indexOf("/A/bwd/6") != -1)
  {
    digitalWrite(DA, HIGH);
    analogWrite(PWMA, 895);
  }
  else if (req.indexOf("/A/bwd/7") != -1)
  {
    digitalWrite(DA, HIGH);
    analogWrite(PWMA, 1023);
  }
  else if ( req.indexOf("/B/break") != -1 ||
            req.indexOf("/B/fwd/0") != -1 ||
            req.indexOf("/B/bwd/0") != -1)
  {
    analogWrite(PWMB, 0);
  }
  else if (req.indexOf("/B/fwd/1") != -1)
  {
    digitalWrite(DB, LOW);
    analogWrite(PWMB, 255);
  }
  else if (req.indexOf("/B/fwd/2") != -1)
  {
    digitalWrite(DB, LOW);
    analogWrite(PWMB, 383);
  }
  else if (req.indexOf("/B/fwd/3") != -1)
  {
    digitalWrite(DB, LOW);
    analogWrite(PWMB, 511);
  }
  else if (req.indexOf("/B/fwd/4") != -1)
  {
    digitalWrite(DB, LOW);
    analogWrite(PWMB, 639);
  }
  else if (req.indexOf("/B/fwd/5") != -1)
  {
    digitalWrite(DB, LOW);
    analogWrite(PWMB, 767);
  }
  else if (req.indexOf("/B/fwd/6") != -1)
  {
    digitalWrite(DB, LOW);
    analogWrite(PWMB, 895);
  }
  else if (req.indexOf("/B/fwd/7") != -1)
  {
    digitalWrite(DB, LOW);
    analogWrite(PWMB, 1023);
  }
  else if (req.indexOf("/B/bwd/1") != -1)
  {
    digitalWrite(DB, HIGH);
    analogWrite(PWMB, 255);
  }
  else if (req.indexOf("/B/bwd/2") != -1)
  {
    digitalWrite(DB, HIGH);
    analogWrite(PWMB, 383);
  }
  else if (req.indexOf("/B/bwd/3") != -1)
  {
    digitalWrite(DB, HIGH);
    analogWrite(PWMB, 511);
  }
  else if (req.indexOf("/B/bwd/4") != -1)
  {
    digitalWrite(DB, HIGH);
    analogWrite(PWMB, 639);
  }
  else if (req.indexOf("/B/bwd/5") != -1)
  {
    digitalWrite(DB, HIGH);
    analogWrite(PWMB, 767);
  }
  else if (req.indexOf("/B/bwd/6") != -1)
  {
    digitalWrite(DB, HIGH);
    analogWrite(PWMB, 895);
  }
  else if (req.indexOf("/B/bwd/7") != -1)
  {
    digitalWrite(DB, HIGH);
    analogWrite(PWMB, 1023);
  }
  else
  {
    Serial.println("invalid request");
    client.stop();
    return;
  }
  client.flush();

  // Prepare the response
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nOK</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");

  // The client will actually be disconnected
  // when the function returns and 'client' object is detroyed
}
