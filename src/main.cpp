#include <Arduino.h>
#include <SPI.h>
#include <AD9833.h>
#include <hfbeacon.h>
#include <avr/pgmspace.h>

// put function declarations here:
int myFunction(int, int);

uint32_t timer_1 = 0;

#define FNC_PIN 4       // Can be any digital IO pin

AD9833 gen(FNC_PIN);       // Defaults to 25MHz internal reference frequency

long freq=10140600;

char txString[] = "RYRYRYRY THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";

int freeRam () 
{
  extern int __heap_start, *__brkval; 
  int v; 
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval); 
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(4,OUTPUT);
  // Serial.begin(57600);
 Serial.print(F("Free RAM : "));
 Serial.println(freeRam());
//  DDS.begin(13,8,9);
//  DDS.calibrate(124998250);
  gen.Begin();
  gen.ApplySignal(SQUARE_WAVE,REG0,freq); // SINE_WAVE // SQUARE_WAVE // HALF_SQUARE_WAVE
  gen.EnableOutput(true);   // Turn ON the output - it defaults to OFF
}

void loop() {
  // put your main code here, to run repeatedly:

  // Beacon.cwTx(freq, txString, 20, &gen);
  //  delay(1000);
   
   Beacon.pskTx(freq, txString, 'B', 31, &gen);
   delay(2000);
   
   //Beacon.rttyTx(freq, txString);
   //delay(2000);
   
   //Beacon.hellTx(freq, txString);
   //delay(2000);
   
   //Beacon.wsprTx(freq, txCall, txLoc, txPow);
   //delay(10000);
   
   Serial.print(F("Free RAM : "));
   Serial.println(freeRam());

}
