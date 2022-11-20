double sens0 = A0;        
double sens1 = A1;
double sens2 = A2;
const double pi = 3.1415926535897932384626433832795;
double map(double x, double in_min, double in_max, double out_min, double out_max){ 
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;  
  }
double Rad(double angle){
    return (pi / 180) * angle;
  }
#include <stdio.h>
#include <stdlib.h>
#include <Servo.h>
Servo myservo9;
#include <math.h>
double x,y,z,x3,y3,z3,a,b,value3,a3,h3,hoek3,hoekG3;
double p1=0.05;

const int c = 30,l = 20,h = 40,r = 0;

double f3(double x,double y,double z,double hoek3){
  x3 = l*sin(hoek3)*cos(Rad(90))+r*cos(Rad(90));
  y3 = l*sin(hoek3)*sin(Rad(90))+r*sin(Rad(90));
  z3 = l*cos(hoek3) + h;

  value3 = pow(c,2) - pow((x3-x),2) - pow((y3-y),2)- pow((z3-z),2);
  return value3;
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
  hoek3 = (a+b)/2;
  while ( abs(f3(x,y,z,hoek3)) > p1){ 
    hoek3=(a+b)/2;
    if (f3(x,y,z,hoek3)*f3(x,y,z,a)>0){
       a=hoek3;
    }
    if (f3(x,y,z,hoek3)*f3(x,y,z,b)>0){
        b=hoek3;
    }
}
hoek3 = hoek3 + Rad(15);
hoekG3 = map(hoek3,0,pi,0,180);
myservo9.write(hoekG3);
}
