 double sens0 = A0;                                                                  
double sens1 = A1;
double sens2 = A2;
const double pi = 3.1415926535897932384626433832795;                               
double map(double x, double in_min, double in_max, double out_min, double out_max){ 
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;  
  }
double ConvertToRadians(double angle){
    return (pi / 180) * angle;
  }
#include <stdio.h>
#include <stdlib.h>
#include <Servo.h>
Servo myservo9;
#include <math.h>
double x,y,z,x1,y1,z1,a,b,value1,a1,h1,hoek1,hoekG1;
double p1=0.05;

const int c = 30,l = 20,h = 40,r = 0;  

double f1(double x,double y,double z,double hoek1){
  x1 = l*sin(hoek1)*cos(ConvertToRadians(-150))+r*cos(ConvertToRadians(-150));
  y1 = l*sin(hoek1)*sin(ConvertToRadians(-150))+r*sin(ConvertToRadians(-150));
  z1 = l*cos(hoek1) + h;

  value1 = -pow((z1-z),2)+ pow(c,2)-pow((x1-x),2)-pow((y1-y),2);
  return value1;
  }

void setup() {
  Serial.begin(9600);
  myservo9.attach(9);
  pinMode(9,OUTPUT);
}

void loop() {
  x = analogRead(sens0);
  x = map(x,0,1023,-15,15);
  y = analogRead(sens1);
  y = map(y,0,1023,-15,15);
  z = analogRead(sens2);
  z = map(z, 0,1023,0,5);
  a = 0;
  b = pi;
  hoek1 = (a+b)/2;
  while ( abs(f1(x,y,z,hoek1)) > p1){ 
    hoek1=(a+b)/2;
    if (f1(x,y,z,hoek1)*f1(x,y,z,a)>0){
       a=hoek1;
    }
    if (f1(x,y,z,hoek1)*f1(x,y,z,b)>0){
        b=hoek1;
    }
}
hoekG1 = map(hoek1,0,pi,0,180);  
myservo9.write(hoekG1);
}
