double sens0 = A0;             //hier worden de 3 potentiometer benoemen en gezegt aan welke 
double sens1 = A1;
double sens2 = A2;
double map(double x, double in_min, double in_max, double out_min, double out_max)  //hier word de map functie gedefineerd met float zodat ze precieser is dan met intigers
  {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }
double ConvertToRadians(double angle)
  {
    return (PI / 180) * angle;
  }
#define PI 3.1415926535897932384626433832795  //PI wordt gedefineerd en ook wiskundige libraries gedefineerd en hoe arduino moet omgaan met servos en de servo zijn naam
#include <stdio.h>
#include <stdlib.h>
#include <Servo.h>
Servo myservo9;
#include <math.h>
double x;
double y;
double z;
double x1;
double y1;
double z1;
double a;
double b;
double value1;

double a1;
double h1;

int c = 30;                   //constantes defineren
int l = 20;
int h = 40;
int r = 0;
double p1 = 0.05;
double p2 = 0.000349;

double hoek1;
double hoekG1;


double f1(double x,double y,double z,double hoek1){
  x1 = l*sin(hoek1)*cos(ConvertToRadians(-150))+r*cos(ConvertToRadians(-150));
  y1 = l*sin(hoek1)*sin(ConvertToRadians(-150))+r*sin(ConvertToRadians(-150));
  z1 = l*cos(hoek1) + h;

  a1 = pow(pow((x1-x),2) + pow((y1-y),2),0.5);
  value1 = -(z1-z)+ pow(abs(pow(c,2)-pow(a1,2)),0.5);
  return value1;
  }

void setup() {
  Serial.begin(9600);
  myservo9.attach(9);
  pinMode(9,OUTPUT);
}

void loop() {
  x = analogRead(sens0);         //hier worden de x y z coordinaat van de kop ingelezen adhv de 3 potentiometer
  x = map(x,0,1023,-15,15);
  y = analogRead(sens1);
  y = map(y,0,1023,-15,15);
  z = analogRead(sens2);
  z = map(z, 0,1023,0,20);
  
  a = 0;
  b = PI;
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
hoekG1 = map(hoek1,0,PI,0,180);
Serial.println(hoekG1);
}
