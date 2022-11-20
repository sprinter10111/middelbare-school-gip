double sens0 = A0;             //hier worden de 3 potentiometer benoemen en gezegt aan welke 
double sens1 = A1;
double sens2 = A2;
double map(double x, double in_min, double in_max, double out_min, double out_max)  //hier word de map functie gedefineerd met float zodat ze precieser is dan met intigers
  {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
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

double aa1;
double a1;
double H1;
double h1;

short c = 30;                   //constantes defineren
short l = 20;
short h = 40;
short r = 0;
double p1 = 0.5;
double p2 = 0.000349;

float hoek1 = 0;
float hoekG1;


double f1(double x,double y,double z,double hoek1){
  x1 = l*sin(hoek1)*cos((-5/6)*PI)+r*cos((-5/6)*PI);
  y1 = l*sin(hoek1)*cos((-5/6)*PI)+r*sin((-5/6)*PI);
  z1 = l*cos(hoek1) + h;

  /*aa1 = pow((x1-x),2)+pow(y1-y,2);
  a1 = pow(pow((x1-x),2)+pow(y1-y,2),0.5);
  H1 = pow(pow(c,2)-pow(pow(pow((x1-x),2)+pow(y1-y,2),0.5),2),2);      //dit is met extra tussenstappen gedaan omdat arduino niet pow(pow(__,__),___) wilt doen
  h1 =pow(pow(pow(c,2)-pow(pow(pow((x1-x),2)+pow(y1-y,2),0.5),2),2),0.25);*/
  value1 = -(z1-z)+ pow(pow(pow(c,2)-pow(pow(pow((x1-x),2)+pow(y1-y,2),0.5),2),2),0.25);
  return value1;
  }






void setup() {
  Serial.begin(9600);
  myservo9.attach(9);
  pinMode(9,OUTPUT);
}

void loop() {
  /*x = analogRead(sens0);         //hier worden de x y z coordinaat van de kop ingelezen adhv de 3 potentiometer
  x = map(x,0,1023,-15,15);
  y = analogRead(sens1);
  y = map(y,0,1023,-15,15);
  z = analogRead(sens2);
  z = map(z, 0,1023,0,20);*/
  x=0;
  y=0;
  z=0;
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
