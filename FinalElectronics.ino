#define trig_pin A2
#define echo_pin A3
#define trig_pin_1 A0
#define echo_pin_1 A1
#define trig_pin_2 A4
#define echo_pin_2 A5
#include <Servo.h>
Servo myservo;
int pos =10;
long distance;
long duration;
long distance_1;
long duration_1;
long distance_2;
long duration_2;
void setup()
{
  Serial.begin(9600);  
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(trig_pin_1,OUTPUT);
  pinMode(echo_pin_1,INPUT);
  pinMode(trig_pin_2,OUTPUT);
  pinMode(echo_pin_2,INPUT);
  pinMode(6,OUTPUT);
  pinMode(10,OUTPUT);
  myservo.attach(9);
  Serial.begin(9600);
  myservo.write(0);
}
void loop() 
{
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);
  duration=pulseIn(echo_pin,HIGH);
  distance=duration*0.017;

  digitalWrite(trig_pin_1,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin_1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin_1,LOW);
  duration_1=pulseIn(echo_pin_1,HIGH);
  distance_1=duration_1*0.017;

  digitalWrite(trig_pin_2,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin_2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin_2,LOW);
  duration_2=pulseIn(echo_pin_2,HIGH);
  distance_2=duration_2*0.017;

  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println();
  Serial.print("distance incoming : ");
  Serial.print(distance_1);
  Serial.println();
  Serial.print("distance out going : ");
  Serial.print(distance_2);
  Serial.println();  
  if (distance_1<10)
  {
    if (distance>20)
    {
      Serial.print("\n\nShip is Entering\n\n");
      analogWrite(6,200);
      analogWrite(10,0);
      if(pos == 10)
    {
    pos=70;
    myservo.write(70);   
    }
    }
    else
    {
      Serial.print("\n\nShip can't Enter Because there's a car on the road\n\n");
      analogWrite(10,200);
      analogWrite(6,0);
    }
  }
  if (distance_2<7 )
  {
    Serial.print("\n\nShip is Leaving\n\n");
    delay(500);
 
    if (pos ==70)
  {
  pos=10;
  myservo.write(pos);
  }
  analogWrite(6,0);
  analogWrite(10,200);
  delay(500);
}
}
