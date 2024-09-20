#include <Arduino.h>

#define GREENLEFT 8
#define YELLOW 9
#define RED 10
#define BLUE 11
#define GREENRIGHT 12

#define LEFT_PHOTORESISTOR A5
#define RIGHT_PHOTORESISTOR A0

#define TRANSMIT_VALUE 9600

#define LOWER_THRESHOLD = -100;
#define MIDDLE_LOW_THRESHOLD = -50;
#define MIDDLE_HIGH_THRESHOLD = 50;
#define UPPER_THRESHOLD = 100;

#define DELAY_TIME = 100;

#define NR_LED = 5;

int photoresistorDifference = 0;

void setup()
{
  Serial.begin(TRANSMIT_VALUE);
  
  pinMode(GREENLEFT, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREENRIGHT, OUTPUT);
}

void loop()
{

  photoresistorDifference = analogRead(RIGHT_PHOTORESISTOR) - analogRead(LEFT_PHOTORESISTOR);

  if (photoresistorDifference < LOWER_THRESHOLD)
    digitalWrite(GREENLEFT, HIGH);
  else if (photoresistorDifference >= LOWER_THRESHOLD && photoresistorDifference < MIDDLE_LOW_THRESHOLD)
    digitalWrite(YELLOW, HIGH);
  else if (photoresistorDifference >= MIDDLE_LOW_THRESHOLD && photoresistorDifference < MIDDLE_HIGH_THRESHOLD)
    digitalWrite(RED, HIGH);
  else if (photoresistorDifference >= MIDDLE_HIGH_THRESHOLD && photoresistorDifference < UPPER_THRESHOLD)
    digitalWrite(BLUE, HIGH);
  else if (photoresistorDifference > UPPER_THRESHOLD)
    digitalWrite(GREENRIGHT, HIGH);

  delay(DELAY_TIME);

  for (int i = 0; i < NR_LED; i++)
  {
    digitalWrite(GREENLEFT + i, LOW);
  }
}
