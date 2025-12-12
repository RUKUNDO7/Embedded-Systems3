#include <SoftwareSerial.h>
const int ledPin = 9;
SoftwareSerial bt(10, 11); // RX, TX
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);   // YOU FORGOT THIS (NEEDED!)
  bt.begin(9600);
}
void loop() {
  static char command = '0';
  if (bt.available()) {
    command = bt.read();
    Serial.print("Received: ");
    Serial.println(command);
  }
  if (command == '1') {
    digitalWrite(ledPin, !digitalRead(ledPin));  // toggle
    command = '0';  // consume the command
  }
}
