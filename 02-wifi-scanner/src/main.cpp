#include <Arduino.h>
#include <WiFi.h>

// put function declarations here:
// int myFunction(int, int);

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("ESP32 WiFi Security Scanner Ready");
}

void loop() {
  Serial.println("\n--- Scanning Networks ---");
  int found = WiFi.scanNetworks();

  if (found == 0) {
    Serial.println("No networks found.");
  } else {
    for (int i = 0; i < found; i++) {
      String ssid       = WiFi.SSID(i);
      int    rssi       = WiFi.RSSI(i);
      String encryption = (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "OPEN !" : "SECURED";

      Serial.print(i + 1);
      Serial.print(". ");
      Serial.print(ssid);
      Serial.print(" | Signal: ");
      Serial.print(rssi);
      Serial.print(" dBm | ");
      Serial.println(encryption);
    }
  }
  Serial.println("--- Scan Complete ---");
  delay(10000); // scan every 10 sec
}

// put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }