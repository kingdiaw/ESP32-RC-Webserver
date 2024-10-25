#include <WiFi.h>
#include <WebServer.h>
#include "html.h"

// WiFi credentials
const char *ssid = "esp32";
const char *password = "JKE@2024";

// ESP32 Web Server on port 80
WebServer server(80);

// HTML code for the control buttons page

// Function to handle incoming client requests
void handleRoot() {
    server.send(200, "text/html", htmlPage);
}

// Function to handle GET requests based on button actions
void handleButtonAction(const String& action) {
    Serial.println("Received action: " + action);
    server.send(200, "text/plain", "Action: " + action);
}

void setup() {
    // Start Serial Monitor
    Serial.begin(115200);
    delay(1000);
    /*
    // Connect to WiFi in STA mode
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to WiFi");

    // Print the IP address
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
*/
    // Set up WiFi AP
    WiFi.softAP(ssid, password);
    IPAddress IP = WiFi.softAPIP();
    Serial.println("ESP32 started as WiFi AP");
    Serial.print("IP Address: ");
    Serial.println(IP);
    // Define HTTP routes
    server.on("/", handleRoot);
    server.on("/F", []() { handleButtonAction("Forward"); });
    server.on("/B", []() { handleButtonAction("Backward"); });
    server.on("/L", []() { handleButtonAction("Left"); });
    server.on("/R", []() { handleButtonAction("Right"); });
    server.on("/S", []() { handleButtonAction("Stop"); });

    // Start server
    server.begin();
    Serial.println("HTTP server started");
}

void loop() {
    // Handle client requests
    server.handleClient();
}
