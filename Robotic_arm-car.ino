char pn;

 #include<AFMotor.h>
#include <Servo.h> // servo library

int l=200;
int pos = 0;
int x=0;
int y=0;

 AF_DCMotor motor1(1);
 AF_DCMotor motor2(2);
 AF_DCMotor motorC(3);
int mot_speed = l;
Servo myservo1, myservo2;

void setup() {
  myservo1.attach(10); // attach servo signal wire to pin 9
  myservo2.attach(9);

  myservo1.write(0);
  myservo1.write(0);
Serial.begin(9600);
}

void loop()
{
    motor1.setSpeed(mot_speed);
  motor2.setSpeed(mot_speed);
  motorC.setSpeed(mot_speed);
 while(Serial.available()>0)
 {
  pn=Serial.read();   
  Serial.print(pn);
}
   if (pn == 'A')
    {
      motor1.run(FORWARD);
      motor2.run(FORWARD);
    }
     if (pn == 'B')
    {
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
    }
     if (pn == 'C')
    {
      motor1.run(FORWARD);
     motor2.run(BACKWARD);
    }
     if (pn == 'D')
    {
      motor2.run(FORWARD);
      motor1.run(BACKWARD);
     
    }
     if (pn == 'Y')
    {
      motorC.run(FORWARD);
      delay(100);
      motorC.run(RELEASE);
      
 
    }
     if (pn == 'X')
    {
      motorC.run(BACKWARD);
       delay(100);
      motorC.run(RELEASE);
      
    }
    if (pn == 'Z')
    {
      motorC.run(RELEASE);
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      
    }
    if (pn == 'a')
    {
     for (pos = x; pos <= 180; pos += 1) { 
    myservo1.write(pos);             
    delay(15);
    x =x+1;
    break;
    pn = 0;
    }}
    if (pn == 'b')
    {
    for (pos = x; pos >= 0; pos -= 1) { 
    myservo1.write(pos);              
    delay(15);
    x =x-1;
    break;
     pn = 0;
    }}
    if (pn == 'c')
    {
       for (pos = y; pos <= 180; pos += 1) { 
    myservo2.write(pos);             
    delay(15);
    y =y+1;
    break;
     pn = 0;
    }}
    if (pn == 'd')
    {
    for (pos = y; pos >= 0; pos -= 1) { 
    myservo2.write(pos);              
    delay(15);
    y =y-1;
    break;
     pn = 0;
    }
    }
      if (pn == 'm')
    {
      l=50;
 
    }
      if (pn == 'n')
    {
    l=100;
 
    }
      if (pn == 'o')
    {
      l=150;
 
    }
      if (pn == 'p')
    {
      l=200;
 
    }
    if (pn == 'q')
    {
      l=255;
 
    }


        }   
