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
double x,y,z,x2,y2,z2,a,b,value2,a2,h2,hoek2,hoekG2;
double p1=0.05;

const int c = 30,l = 20,h = 40,r = 0;                                                 //constantes defineren

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
  x = analogRead(sens0);                                                              //hier worden de x y z coordinaat van de kop ingelezen adhv de 3 potentiometer
  x = map(x,0,1023,-15,15);
  y = analogRead(sens1);
  y = map(y,0,1023,-15,15);
  z = analogRead(sens2);
  z = map(z, 0,1023,0,20);
  a = 0;
  b = pi;
  hoek2 = (a+b)/2;
  while ( abs(f2(x,y,z,hoek2)) > p1){                                                 //in deze while loop wordt er een juist hoek gegokt met de methode van het midden
    hoek2=(a+b)/2;
    if (f2(x,y,z,hoek2)*f2(x,y,z,a)>0){
       a=hoek2;
    }
    if (f2(x,y,z,hoek2)*f2(x,y,z,b)>0){
        b=hoek2;
    }
}
hoekG2 = map(hoek2,0,pi,0,180);                                                       //hier wordt de hoek van radialen naar graden omgevormt in een map functie omdat de servo zich anders niet wilt bewegen
myservo9.write(hoekG2);
Serial.println(hoekG2);
delay(10);
}
