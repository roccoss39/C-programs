#include <Arduino.h>

#define GREENLEFT 8
#define YELLOW 9
#define RED 10
#define BLUE 11
#define GREENRIGHT 12
#define LEFT_PHOTORESISTOR A5
#define RIGHT_PHOTORESISTOR A0

int photoresistorDifference = 0;
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

  photoresistorDifference = (analogRead(RIGHT_PHOTORESISTOR)) - (analogRead(LEFT_PHOTORESISTOR));

  if (photoresistorDifference < -100)
    digitalWrite(GREENLEFT, HIGH);
  else if (photoresistorDifference >= -100 && photoresistorDifference < -50)
    digitalWrite(YELLOW, HIGH);
  else if (photoresistorDifference >= -50 && photoresistorDifference < 50)
    digitalWrite(RED, HIGH);
  else if (photoresistorDifference >= 50 && photoresistorDifference < 100)
    digitalWrite(BLUE, HIGH);
  else if (photoresistorDifference > 100)
    digitalWrite(GREENRIGHT, HIGH);

  delay(100);

  for (int i = 0; i < nrLed; i++)
  {
    digitalWrite(GREENLEFT + i, LOW);
  }
}
