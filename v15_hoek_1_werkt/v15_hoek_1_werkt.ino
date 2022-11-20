double sens0 = A0;                                                                  //hier worden de 3 potentiometer benoemen en gezegt aan welke 
double sens1 = A1;
double sens2 = A2;
const double pi = 3.1415926535897932384626433832795;                                //PI wordt gedefineerd en ook wiskundige libraries gedefineerd en hoe arduino moet omgaan met servos en de servo zijn naam
double map(double x, double in_min, double in_max, double out_min, double out_max){ //hier wordt de map functie gedefineerd met float zodat ze precieser is dan met intigers
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;  
  }
double ConvertToRadians(double angle){                                               //hier wordt een functie gedefineerd om van graden naar radialen te gaan
    return (pi / 180) * angle;
  }
#include <stdio.h>
#include <stdlib.h>
#include <Servo.h>
Servo myservo9;
#include <math.h>
double x,y,z,x1,y1,z1,a,b,value1,a1,h1,hoek1,hoekG1;
double p1=0.05;

const int c = 30,l = 20,h = 40,r = 0;                                                 //constantes defineren

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
  x = analogRead(sens0);                                                              //hier worden de x y z coordinaat van de kop ingelezen adhv de 3 potentiometer
  x = map(x,0,1023,-15,15);
  y = analogRead(sens1);
  y = map(y,0,1023,-15,15);
  z = analogRead(sens2);
  z = map(z, 0,1023,0,5);
  a = 0;
  b = pi;
  hoek1 = (a+b)/2;
  while ( abs(f1(x,y,z,hoek1)) > p1){                                                 //in deze while loop wordt er een juist hoek gegokt met de methode van het midden
    hoek1=(a+b)/2;
    if (f1(x,y,z,hoek1)*f1(x,y,z,a)>0){
       a=hoek1;
    }
    if (f1(x,y,z,hoek1)*f1(x,y,z,b)>0){
        b=hoek1;
    }
}
hoekG1 = map(hoek1,0,pi,0,180);                                                       //hier wordt de hoek van radialen naar graden omgevormt in een map functie omdat de servo zich anders niet wilt bewegen
myservo9.write(hoekG1);
Serial.println(hoekG1);
}
