#include <Arduino.h>

/* Po uruchomieniu programu należy przekręcić potencjometr w losowe miejsce i wcisnąć przycisk.
Wtedy Arduino powinno wyświetlić na PC komunikat:

Podaj liczbę:

Jeśli wysłana do Arduino liczba będzie zgadzała się z odczytem ADC o +/- 50,
to gracz wygrywa. W przeciwnym wypadku włącza się żółta dioda i gracz ma jeszcze 2 próby.
Gdy za każdym razem zostanie wpisana zła liczba, to na płytce stykowej włącza się czerwona dioda. Natomiast w przypadku wygranej zielona */

#define GREEN 8
#define YELLOW 9
#define RED 10
#define SWITCH 11

short int ReadVal16 = 0;
short int UserVal16 = 0;
byte Try = 0;

void setup() {
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);   // Konfiguracja wyjść pod diody LED
  pinMode(YELLOW, OUTPUT);   // Konfiguracja wyjść pod diody LED
  pinMode(RED, OUTPUT);  // Konfiguracja wyjść pod diody LED
  pinMode(SWITCH, INPUT_PULLUP);
}

void loop() {
  ReadVal16 = analogRead(A5);
  Serial.println("Change position of resistor and push the switch");

  while (((analogRead(A5) < ReadVal16 + 3) && (analogRead(A5) > ReadVal16 - 3) || digitalRead(SWITCH) == HIGH)) {};

 ReadVal16 = analogRead(A5);
  Serial.println("ReadVal16:" + String(ReadVal16));

  do {
    Serial.println("GUESS VALUE 0-1023:");
    while (Serial.available() <= 0) {};

    UserVal16 = (Serial.readStringUntil('\n')).toInt();
    Serial.println(UserVal16);

    if ((UserVal16 > ReadVal16 - 50) && (UserVal16 < ReadVal16 + 50)) {
      Serial.println("Win!");
      digitalWrite(YELLOW, LOW);
      digitalWrite(GREEN, HIGH);
      delay(1000);
      digitalWrite(GREEN, LOW);
      Try = 3;
    } else {
      Serial.println("Try again!");
      digitalWrite(YELLOW, HIGH);
      digitalWrite(RED, HIGH);
      delay(1000);
      digitalWrite(RED, LOW);
      Try++;
   }

  } while  (Try != 3);

  digitalWrite(YELLOW, LOW);
  Try = 0;
}
