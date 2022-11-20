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

short c = 30;
short l = 20;
short h = 40;
double p1 = 0.5;
double p2 = 0.000349;

float hoek = 0;
float hoekG;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(9,OUTPUT);
}

void loop() {
  float value1 = 1;
  
  x = analogRead(sens0);        //hier worden de x y z coordinaat van de kop ingelezen adhv de 3 potentiometer
  x = map(x,0,1023,-15,15);
  /*y = analogRead(sens1);
  y = map(y,0,1023,-15,15);
  z = analogRead(sens2);
  z = map(z, 0,1023,0,20);*/
  y=1;
  z=1;

  while(abs(value1)>p1) {   // dit is de wiskunde formule om de hoek te bereken als de hoek juist is dan is value1 bijna 0
    hoek = hoek + p2;
    value1 = -pow((l*cos(hoek) + h - z),2)+pow(c,2) - (pow(-l*sin(hoek)*cos(-(5/6)*PI)-x,2)+ pow(-l*sin(hoek)*sin(-(5/6)*PI)-y,2));
    if (hoek>PI)  //de hoek zit tussen 0 en PI radialen dus als de hoek groter word dan PI wordt hij terug gezet naar 0 rad
    {
      hoek=0;
    }
     
  }
  hoekG = map(hoek,0,PI,0,180); //hier verandert de hoek van radialen en wordt hij hoekG benoemd
  myservo.write(hoekG);   //hier zou de servo zich moeten aanpassen afhankelijk van w1 maar dat doet hij maar 1 keer
  hoek = hoek - 0.1;      // als hoek is een juiste waarde als de coordinaten wat veranderen zal de volgende hoek rond de vorige hoek zijn
}
