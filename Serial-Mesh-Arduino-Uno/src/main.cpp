#include <Arduino.h>

#include <SoftwareSerial.h>

// trying to swap pins, it works, TX then RX!
SoftwareSerial HC12(8, 10); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HC12.begin(9600);
      
}

void loop() {
  // put your main code here, to run repeatedly:
  while (HC12.available()) {        // If HC-12 has data
    Serial.write(HC12.read());      // Send the data to Serial monitor
  }
  while (Serial.available()) {      // If Serial monitor has data
    HC12.write(Serial.read());      // Send that data to HC-12
  }
}

// encode JSON message
// JSON sucks, just write header protocol

// send entire message at once
// look into protocals for sending messages

// include message ID
// include a device ID as part of message ID
// if receive message with knwon ID, throw it away
// if receive message with unknown ID, store it and send it out again

// include message jump count
// if receive message with jump count less than max jumps increment jump count and send it out again

// what if two devices send a message at the same time?
// all devices have multiple channels, perhaps hop channels after each message?

// designate Gateways, Repeaters, and Endpoints.
// Gateways dont repeat messages
// Endpoints dont receive messages
// Repeaters repeat messages, surprise
// this may reduce the chance of receiving multiple messages at once

//or perhaps just gateways and repeaters
