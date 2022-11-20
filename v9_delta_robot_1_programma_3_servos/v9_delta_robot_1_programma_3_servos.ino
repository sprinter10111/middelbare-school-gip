double sens0 = A0;             //hier worden de 3 potentiometer benoemen en gezegt aan welke 
double sens1 = A1;
double sens2 = A2;
float map(float x, float in_min, float in_max, float out_min, float out_max)  //hier word de map functie gedefineerd met float zodat ze precieser is dan met intigers
  {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  }
#define PI 3.1415926535897932384626433832795  //PI wordt gedefineerd en ook wiskundige libraries gedefineerd en hoe arduino moet omgaan met servos en de servo zijn naam
#include <stdio.h>
#include <stdlib.h>
#include <Servo.h>
Servo myservo9,myservo10,myservo11;
 
float x;
float y;
float z;

short c = 30;                   //constantes defineren
short l = 20;
short h = 40;
double p1 = 0.5;
double p2 = 0.000349;

float hoek1 = 0;
float hoek2 = 0;
float hoek3 = 0;

float hoekG1;
float hoekG2;
float hoekG3;

void setup() {
  Serial.begin(9600);
  myservo9.attach(9);
  pinMode(9,OUTPUT);
  myservo10.attach(10);
  pinMode(10,OUTPUT);
  myservo11.attach(11);
  pinMode(11,OUTPUT);
}

void loop(){
  servo1();
  servo2();
  servo3();
}

void servo1() {
  float value1 = 1;              //de line is er om te verzekeren dat het in de while gestoken wordt
  
  x = analogRead(sens0);         //hier worden de x y z coordinaat van de kop ingelezen adhv de 3 potentiometer
  x = map(x,0,1023,-15,15);
  y = analogRead(sens1);
  y = map(y,0,1023,-15,15);
  z = analogRead(sens2);
  z = map(z, 0,1023,0,20);

  while(abs(value1)>p1) {        // dit is de wiskunde formule om de hoek te bereken als de hoek juist is dan is value2 bijna 0
    hoek1 = hoek1 + p2;
    value1 = -pow((l*cos(hoek1) + h - z),2)+pow(c,2) - (pow(-l*sin(hoek1)*cos(-(5/6)*PI)-x,2)+ pow(-l*sin(hoek1)*sin(-(5/6)*PI)-y,2));
    if (hoek1>PI)                //de hoek zit tussen 0 en PI radialen dus als de hoek groter word dan PI wordt hij terug gezet naar 0 rad
    {
      hoek1=0;
    }
     
  }
  hoekG1 = map(hoek1,0,PI,0,180); //hier verandert de hoek van radialen en wordt hij hoekG benoemd
  myservo9.write(hoekG1);         //hier past de servo zijn hoek afhanklijk van de waarde van hoekG1
  hoek1 = hoek1 - 0.1;            // als hoek is een juiste waarde als de coordinaten wat veranderen zal de volgende hoek rond de vorige hoek zijn
}

void servo2() {
  float value2 = 1;              //de line is er om te verzekeren dat het in de while gestoken wordt
  
  x = analogRead(sens0);         //hier worden de x y z coordinaat van de kop ingelezen adhv de 3 potentiometer
  x = map(x,0,1023,-15,15);
  y = analogRead(sens1);
  y = map(y,0,1023,-15,15);
  z = analogRead(sens2);
  z = map(z, 0,1023,0,20);

  while(abs(value2)>p1) {        // dit is de wiskunde formule om de hoek te bereken als de hoek juist is dan is value2 bijna 0
    hoek2 = hoek2 + p2;
    value2 = -pow((l*cos(hoek2) + h - z),2)+pow(c,2) - (pow(l*sin(hoek2)*cos(-(1/6)*PI)-x,2)+pow(l*sin(hoek2)*sin(-(1/6)*PI),2));
    if (hoek2>PI)                //de hoek zit tussen 0 en PI radialen dus als de hoek groter word dan PI wordt hij terug gezet naar 0 rad
    {
      hoek2=0;
    }
     
  }
  hoekG2 = map(hoek2,0,PI,0,180); //hier verandert de hoek van radialen en wordt hij hoekG benoemd
  myservo10.write(hoekG2);         //hier past de servo zijn hoek afhanklijk van de waarde van hoekG2
  hoek2 = hoek2 - 0.1;            // als hoek is een juiste waarde als de coordinaten wat veranderen zal de volgende hoek rond de vorige hoek zijn
}

void servo3() {
  float value3 = 1;              //de line is er om te verzekeren dat het in de while gestoken wordt
  
  x = analogRead(sens0);         //hier worden de x y z coordinaat van de kop ingelezen adhv de 3 potentiometer
  x = map(x,0,1023,-15,15);
  y = analogRead(sens1);
  y = map(y,0,1023,-15,15);
  z = analogRead(sens2);
  z = map(z, 0,1023,0,20);

  while(abs(value3)>p1) {        // dit is de wiskunde formule om de hoek te bereken als de hoek juist is dan is value3 bijna 0
    hoek3 = hoek3 + p2;
    value3 = -pow((l*cos(hoek3) + h - z),2)+pow(c,2) - (pow(l*sin(hoek3)*cos((1/2)*PI)-x,2)+pow(l*sin(hoek3)*sin((1/2)*PI),2));
    if (hoek3>PI)                //de hoek zit tussen 0 en PI radialen dus als de hoek groter word dan PI wordt hij terug gezet naar 0 rad
    {
      hoek3=0;
    }
     
  }
  hoekG3 = map(hoek3,0,PI,0,180); //hier verandert de hoek van radialen en wordt hij hoekG benoemd
  myservo11.write(hoekG3);        //hier past de servo zijn hoek afhanklijk van de waarde van hoekG2
  hoek3 = hoek3 - 0.1;            // als hoek is een juiste waarde als de coordinaten wat veranderen zal de volgende hoek rond de vorige hoek zijn
}
