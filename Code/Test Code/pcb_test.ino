#include "AD9833.h"
#include "SPI.h"

AD9833 AD;
//for PWM
const int SW_PWM = 17;
const int PWMChannel = 0;
const int resolution = 8;
const int dutyCycle = 128;

//digital control
bool current_protect=1, HW_interlock=1, ON_OFF=1, AC_sig=1, DC_sig=1;


void setup() {
  Serial.begin(9600);
  
  //set mode for digital pins
  pinMode(16, OUTPUT); // Current_protect
  //pinMode(34, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);

  // for initial test
  control(current_protect, 16);
  //control(HW_interlock, 34);
  control(ON_OFF, 19);
  control(AC_sig, 21);
  control(DC_sig, 22);

  //for 12V boost
  digitalWrite(25, HIGH);
  digitalWrite(25, LOW);
  digitalWrite(25, LOW);

  //function gen
  AD.selectVSPI();
  AD.begin(5);
  AD.setWave(AD9833_SINE);
  AD.setFrequency(1000.0, 0);
  AD.setFrequencyChannel(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  // just chilling
}

void control(bool test, int pin)
{
  if(test==1){
    digitalWrite(pin, HIGH);
  }
  else{
    digitalWrite(pin, LOW);
  }
}
