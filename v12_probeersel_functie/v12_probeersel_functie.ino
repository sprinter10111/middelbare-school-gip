double sens0 = A0;             //hier worden de 3 potentiometer benoemen en gezegt aan welke 
double sens1 = A1;
double sens2 = A2;
double map(double x, double in_min, double in_max, double out_min, double out_max)  //hier word de map functie gedefineerd met float zodat ze precieser is dan met intigers
  {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }
const double pi = 3.1415926535897932384626433832795; //PI wordt gedefineerd en ook wiskundige libraries gedefineerd en hoe arduino moet omgaan met servos en de servo zijn naam
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

int c = 30;                   //constantes defineren
int l = 20;
int h = 40;
int r = 0;
double p1 = 0.5;
double p2 = 0.000349;

double hoek1 = 0;
double hoekG1;


double f1(double x,double y,double z,double hoek1){
  x1 = l*sin(hoek1)*cos((-5/6)*pi)+r*cos((-5/6)*pi);
  y1 = l*sin(hoek1)*sin((-5/6)*pi)+r*sin((-5/6)*pi);
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
void loop(){
  x=15;
  y=-8;
  z=3;
  hoek1=0*pi/180;
  Serial.println(f1(x,y,z,hoek1));
}
