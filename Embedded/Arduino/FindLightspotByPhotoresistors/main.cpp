#include <Arduino.h>

#define GREENLEFT 8
#define YELLOW 9
#define RED 10
#define BLUE 11
#define GREENRIGHT 12
#define LEFT_PHOTORESISTOR A5
#define RIGHT_PHOTORESISTOR A0

int photoresistorDefference = 0;
const byte nrLed = 5;


void setup()
{
  Serial.begin(9600);
  pinMode(GREENLEFT, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREENRIGHT, OUTPUT);
}

void loop()
{
  // digitalWrite(GREENLEFT, HIGH);
  // Serial.println("Left Photoresistor:" + String(analogRead(LEFT_PHOTORESISTOR)));
  // Serial.println("Right Photoresistor:" + String(analogRead(RIGHT_PHOTORESISTOR)));
  //delay(1000);

  photoresistorDefference = (analogRead(RIGHT_PHOTORESISTOR)) - (analogRead(LEFT_PHOTORESISTOR));

  if (photoresistorDefference < -100)
    digitalWrite(GREENLEFT, HIGH);
  else if (photoresistorDefference >= -100 && photoresistorDefference < -50)
    digitalWrite(YELLOW, HIGH);
  else if (photoresistorDefference >= -50 && photoresistorDefference < 50)
    digitalWrite(RED, HIGH);
  else if (photoresistorDefference >= 50 && photoresistorDefference < 100)
    digitalWrite(BLUE, HIGH);
  else if (photoresistorDefference > 100)
    digitalWrite(GREENRIGHT, HIGH);

  delay(100);

  for (int i = 0; i < nrLed; i++)
  {
    digitalWrite(GREENLEFT + i, LOW);
  }
}
