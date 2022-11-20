int Pin0 = 10;
int Pin1 = 11;
int Pin2 = 12;
int Pin3 = 13;
int msDelay = 10;
void setup()
{
 pinMode(Pin0, OUTPUT);
 pinMode(Pin1, OUTPUT);
 pinMode(Pin2, OUTPUT);
 pinMode(Pin3, OUTPUT);
}
void loop()
{
 digitalWrite(Pin0, HIGH);
 digitalWrite(Pin1, LOW);
 digitalWrite(Pin2, LOW);
 digitalWrite(Pin3, LOW);
 
delay(msDelay);
 digitalWrite(Pin0, HIGH);
 digitalWrite(Pin1, HIGH);
 digitalWrite(Pin2, LOW);
 digitalWrite(Pin3, LOW);
delay(msDelay);
 digitalWrite(Pin0, LOW);
 digitalWrite(Pin1, HIGH);
 digitalWrite(Pin2, LOW);
 digitalWrite(Pin3, LOW);
 
delay(msDelay);
 digitalWrite(Pin0, LOW);
 digitalWrite(Pin1, HIGH);
 digitalWrite(Pin2, HIGH);
 digitalWrite(Pin3, LOW);
delay(msDelay);
 digitalWrite(Pin0, LOW);
 digitalWrite(Pin1, LOW);
 digitalWrite(Pin2, HIGH);
 digitalWrite(Pin3, LOW);
 
delay(msDelay);
 digitalWrite(Pin0, LOW);
 digitalWrite(Pin1, LOW);
 digitalWrite(Pin2, HIGH);
 digitalWrite(Pin3, HIGH);
delay(msDelay);
 digitalWrite(Pin0, LOW);
 digitalWrite(Pin1, LOW);
 digitalWrite(Pin2, LOW);
 digitalWrite(Pin3, HIGH);
delay(msDelay);
 digitalWrite(Pin0, HIGH);
 digitalWrite(Pin1, LOW);
 digitalWrite(Pin2, LOW);
 digitalWrite(Pin3, HIGH);
 
delay(msDelay);
}
