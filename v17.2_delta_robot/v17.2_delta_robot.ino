double sens0 = A0;   
double sens1 = A1;
double sens2 = A2;
double map(double x, double in_min, double in_max, double out_min, double out_max){ 
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;  
  }
double ConvertToRadians(double angle){ 
    return (pi / 180) * angle;
  }
#include <stdlib.h>
#include <Servo.h>
Servo myservo9;
#include <math.h>
double x,y,z,x2,y2,z2,a,b,value2,a2,h2,hoek2,hoekG2;
double p1=0.05;
const double pi = 3.1415926535897932384626433832795;
const int c = 30,l = 20,h = 40,r = 0;

double f2(double x,double y,double z,double hoek2){
  x2 = l*sin(hoek2)*cos(ConvertToRadians(-30))+r*cos(ConvertToRadians(-30));
  y2 = l*sin(hoek2)*sin(ConvertToRadians(-30))+r*sin(ConvertToRadians(-30));
  z2 = l*cos(hoek2) + h;

  a2 = pow(pow((x2-x),2) + pow((y2-y),2),0.5);
  value2 = -(z2-z)+ pow(abs(pow(c,2)-pow(a2,2)),0.5);
  return value2;
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
  z = map(z, 0,1023,0,20);
  a = 0;
  b = pi;
  hoek2 = (a+b)/2;
  while ( abs(f2(x,y,z,hoek2)) > p1){
    hoek2=(a+b)/2;
    if (f2(x,y,z,hoek2)*f2(x,y,z,a)>0){
       a=hoek2;
    }
    if (f2(x,y,z,hoek2)*f2(x,y,z,b)>0){
        b=hoek2;
    }
}
hoekG2 = map(hoek2,0,pi,0,180);
#include <stdio.h>
myservo9.write(hoekG2);
Serial.println(hoekG2);
delay(10);
}
