#include <Servo.h>

#define SERVO_PIN 6
#define MAX_POSITION 180
#define POSITION_CHANGE 6
#define DELAY_MS 200

Servo servoMechanism;
int position = 0;

void setup() 
{ 
  servoMechanism.attach(SERVO_PIN);
} 

void loop() 
{  
  if (position < MAX_POSITION) {
    servoMechanism.write(position);
  } else {
    position = 0;
  }    
  
  position += POSITION_CHANGE;
  delay(DELAY_MS);
}
