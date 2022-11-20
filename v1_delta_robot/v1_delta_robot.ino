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
Servo myservo9, myservo10, myservo11; 

float x;
float y;
float z;

int c = 30;
int l = 20;
int r = 0;
int h = 40;
double p1 = 0.005;
double p2 = 0.0002;

double w1 = (5*PI)/6;
double w2 = (5*PI)/6;
double w3 = (5*PI)/6;

void setup() {
  Serial.begin(9600);
  myservo9.attach(9);  
  myservo10.attach(10);  
  myservo11.attach(11);  

  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  double waarde1 = 1;
  double waarde2 = 1;
  double waarde3 = 1;
  
  x = analogRead(sens0);
  x = map(x,0,1023,-15,15);
  y = analogRead(sens1);
  y = map(x,0,1023,-15,15);
  z = analogRead(sens2);
  z = map(z, 0,1023,0,20);
  Serial.println(x);
 } 
  /*while(abs(waarde1)>p1) {
    w1 = w1 + p2;
    waarde1 = -pow((l*cos(w1) + h - z),2)+pow(c,2) - (pow(l*sin(w1)*cos(-(5/6)*PI)-x,2)+pow(l*sin(w1)*sin(-(5/6)*PI),2));   
  }
  while(abs(waarde2)>p1) {
    w2 = w2 + p2;
    waarde2 = -pow((l*cos(w2) + h - z),2)+pow(c,2) - (pow(l*sin(w2)*cos(-(1/6)*PI)-x,2)+pow(l*sin(w2)*sin(-(1/6)*PI),2));
    
  }
  while(abs(waarde3)>p1) {
    w3 = w3 + p2;
    waarde1 = -pow((l*cos(w3) + h - z),2)+pow(c,2) - (pow(l*sin(w3)*cos((1/2)*PI)-x,2)+pow(l*sin(w3)*sin((1/2)*PI),2));
  }
   
   w1=w1*(PI/180);
   w2=w2*(PI/180);
   w3=w3*(PI/180);
   
   myservo9.write(w1);
   myservo10.write(w2);
   myservo11.write(w3); */ 
 
