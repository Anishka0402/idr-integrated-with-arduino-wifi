#include <Arduino.h>
int ldrPin = A0; // LDR connected to analog pin A0
void setup() {
// write your initialization code here
    Serial.begin(9600); // Start serial communication at 9600 baud rate
    pinMode(ldrPin, INPUT); // Set the LDR pin as an input

}

void loop() {
// write your code here
    int ldrValue=analogRead(ldrPin);
    int lightPercentage=map(ldrValue,0,1023,100,0);
    Serial.print("LDR value");
    Serial.println(ldrValue);
    Serial.print("Light percentage");
    Serial.print(lightPercentage);
    Serial.println("%");

    delay(300);
}