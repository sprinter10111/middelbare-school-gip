double sens0 = A0;
double sens1 = A1;
double sens2 = A2;
float map(float x, float in_min, float in_max, float out_min, float out_max)
  {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }
#define PI 3.1415926535897932384626433832795
#include <stdio.h>
#include <stdlib.h>
#include <Servo.h>
Servo myservo;
 
float x;
float y;
float z;

int c = 30;
int l = 20;
int h = 40;
double p1 = 0.5;
double p2 = 0.000349;

double hoek = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(9,OUTPUT);
}

void loop() {
  double value1 = 1;
  
  x = analogRead(sens0);
  x = map(x,0,1023,-15,15);
  /*y = analogRead(sens1);
  y = map(y,0,1023,-15,15);
  z = analogRead(sens2);
  z = map(z, 0,1023,0,20);*/
  y=1;
  z=1;

  while(abs(value1)>p1) {
    hoek = hoek + p2;
    value1 = -pow((l*cos(hoek) + h - z),2)+pow(c,2) - (pow(-l*sin(hoek)*cos(-(5/6)*PI)-x,2)+ pow(-l*sin(hoek)*sin(-(5/6)*PI)-y,2));
    if (hoek>PI)
    {
      hoek=0;
    }
    //Serial.println(w1);   
  } 
  myservo.write(hoek*(PI/180));  //hier zou de servo zich moeten aanpassen afhankelijk van w1 maar dat doet hij maar 1 keer
  delay(15);                     //wachten tot de servo er geraakt?
  hoek = hoek - 0.1; 
  //Serial.println("JAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA");
}
