#include <Arduino.h>

// put function declarations here:
// int myFunction(int, int);

void setup() {
  pinMode(2, OUTPUT);    // Build-in LED GPIO
}

void loop() {
  digitalWrite(2, HIGH); // LED On
  delay(2000);           // wait 2 sec
  digitalWrite(2, LOW);  // LED Off
  delay(1000);           // wait 1 sec
}

// put function definitions here:
// int myFunction(int x, int y) {
//  /return x + y;
// }