#include <Servo.h>

int pos1 = 1500;
int pos2 = 1500;
int pos3 = 1500;
int pos4 = 1500;
int pos5 = 1500;
int pos6 = 1500;

float pos1Scaled;
float pos2Scaled;
float pos3Scaled;
float pos4Scaled;
float pos5Scaled;
float pos6Scaled;

float pos1Smoothed = 1500;
float pos2Smoothed = 1500;
float pos3Smoothed = 1500;
float pos4Smoothed = 1500;
float pos5Smoothed = 1500;
float pos6Smoothed = 1500;

float pos1SmoothedPrev = 1500;
float pos2SmoothedPrev = 1500;
float pos3SmoothedPrev = 1500;
float pos4SmoothedPrev = 1500;
float pos5SmoothedPrev = 1500;
float pos6SmoothedPrev = 1500;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

void setup() {

  Serial.begin(115200);

  servo1.attach(4);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(7);
  servo5.attach(8);
  servo6.attach(9);

  servo1.writeMicroseconds(1500); // ALL SERVOS START FROM THE MEDIUM VALUE WHICH IS THE CENTER
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1500);
  servo4.writeMicroseconds(1500);
  servo5.writeMicroseconds(1500);
  servo6.writeMicroseconds(1500);

}

void loop() {


      // step sequencer بداية العمليات
     // F مثلا نعطي قيم للموتورات حتى تقوم الذراع بالترحيب
        pos1 = 1800; // f نعطي قيم لكل سيرفو ما بين 0 و 1024 وبعدين بنحول الرينج تبعها إلى رينج السيرفو اللي بين 700 و2400
        pos2 = 2000;
        pos3 = 900;
        pos4 = 1100;
        pos5 = 1400;
        pos6 = 2100;


      pos1SmoothedPrev = (pos1 * 0.99);
      pos2SmoothedPrev = (pos2 * 0.99);
      pos3SmoothedPrev = (pos3 * 0.99);
      pos4SmoothedPrev = (pos4 * 0.99);
      pos5SmoothedPrev = (pos5 * 0.99);
      pos6SmoothedPrev = (pos6 * 0.99);

 
      // smooth pots
      
      pos1Smoothed = (pos1 * 0.01) + (pos1SmoothedPrev * 0.99); // we move the servo slowly to make the movement smooth
      pos2Smoothed = (pos2 * 0.01) + (pos2SmoothedPrev * 0.99);
      pos3Smoothed = (pos3 * 0.01) + (pos3SmoothedPrev * 0.99);
      pos4Smoothed = (pos4 * 0.05) + (pos4SmoothedPrev * 0.99);
      pos5Smoothed = (pos5 * 0.01) + (pos5SmoothedPrev * 0.99);
      pos6Smoothed = (pos6 * 0.01) + (pos6SmoothedPrev * 0.99);  
    
      // bookmark previous values
    
      pos1SmoothedPrev = pos1Smoothed;
      pos2SmoothedPrev = pos2Smoothed;
      pos3SmoothedPrev = pos3Smoothed;
      pos4SmoothedPrev = pos4Smoothed;
      pos5SmoothedPrev = pos5Smoothed;
      pos6SmoothedPrev = pos6Smoothed;
  
      Serial.print(pos1Smoothed);
      Serial.print(" , ");
      Serial.print(pos2Smoothed);
      Serial.print(" , ");
      Serial.print(pos3Smoothed);
      Serial.print(" , ");
      Serial.print(pos4Smoothed);
      Serial.print(" , ");
      Serial.print(pos5Smoothed);
      Serial.print(" , ");
      Serial.println(pos6Smoothed);

      // write servos

      servo1.writeMicroseconds(pos1Smoothed);                     
      servo2.writeMicroseconds(pos2Smoothed);      
      servo3.writeMicroseconds(pos3Smoothed);     
      servo4.writeMicroseconds(pos4Smoothed);                   
      servo5.writeMicroseconds(pos5Smoothed);
      servo6.writeMicroseconds(pos6Smoothed);                     


} // end if main loop
