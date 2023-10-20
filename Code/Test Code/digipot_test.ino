#include <SPI.h>

// Pins for SPI comms
#define DATA  23      // SPI Data pin number
#define CLK   18      // SPI Clock pin number
#define CS_DIGIPOT 5  // MCP41010 chip select - digital potentiometer.

void write_digipot(int val) {
  //  https://www.best-microcontroller-projects.com/mcp41010.html
  //  take the CS pin low to select the chip:
  digitalWrite(CS_DIGIPOT,LOW);
  //  send in the address and value via SPI:
  SPI.transfer(B00010001);
  //  write out the value
  SPI.transfer(val);
  //  take the CS pin high to de-select the chip:
  digitalWrite(CS_DIGIPOT,HIGH);
  SPI.endTransaction();
}

void setup() {
  pinMode(CS_DIGIPOT,OUTPUT);
  Serial.begin(9600);
  SPI.begin(); // Set pins as outputs for SPI hardware.

  write_digipot(0); // Set MCP41010 to mid point.
}

void loop(void) {
  for(int pot = 0; pot <= 256; pot++){
    write_digipot(pot);
    delay(100);
    Serial.println(pot);
    Serial.println(analogRead(15));
    Serial.println("----------------------------------");
  }
}
