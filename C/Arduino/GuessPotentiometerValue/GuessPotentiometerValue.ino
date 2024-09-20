#include <Arduino.h>

/* After starting the program, turn the potentiometer to a random position and press the button.
Then, Arduino should display the message on the PC:

Enter a number:

If the number sent to Arduino matches the ADC reading within a margin of +/- 50, 
the player wins. Otherwise, the yellow LED turns on, and the player has 2 more attempts.
If an incorrect number is entered on each attempt, the red LED on the breadboard will turn on.
In case of a win, the green LED will light up. */

#define GREEN_LED_PIN 8
#define YELLOW_LED_PIN 9
#define RED_LED_PIN 10
#define SWITCH_PIN 11
#define ADC_TOLERANCE 50
#define MAX_TRIES 3
#define DELAY_TIME_MS 1000
#define POTENTIOMETER_TOLERANCE 3

short int ReadVal16 = 0;
short int UserVal16 = 0;
byte Try = 0;

void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(YELLOW_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(SWITCH_PIN, INPUT_PULLUP);
}

void loop() {
  ReadVal16 = analogRead(A5);
  Serial.println("Change position of resistor and push the switch");

  while ((abs(analogRead(A5) - ReadVal16) < POTENTIOMETER_TOLERANCE) || digitalRead(SWITCH_PIN) == HIGH) {};

  ReadVal16 = analogRead(A5);
  Serial.println("ReadVal16: " + String(ReadVal16));

  do {
    Serial.println("GUESS VALUE 0-1023:");
    while (Serial.available() <= 0) {};

    UserVal16 = (Serial.readStringUntil('\n')).toInt();
    Serial.println(UserVal16);

    if (abs(UserVal16 - ReadVal16) <= ADC_TOLERANCE) {
      Serial.println("Win!");
      digitalWrite(YELLOW_LED_PIN, LOW);
      digitalWrite(GREEN_LED_PIN, HIGH);
      delay(DELAY_TIME_MS);
      digitalWrite(GREEN_LED_PIN, LOW);
      Try = MAX_TRIES;
    } else {
      Serial.println("Try again!");
      digitalWrite(YELLOW_LED_PIN, HIGH);
      digitalWrite(RED_LED_PIN, HIGH);
      delay(DELAY_TIME_MS);
      digitalWrite(RED_LED_PIN, LOW);
      Try++;
    }

  } while (Try < MAX_TRIES);

  digitalWrite(YELLOW_LED_PIN, LOW);
  Try = 0;
}
