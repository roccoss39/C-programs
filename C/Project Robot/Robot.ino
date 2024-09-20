#include "Robot.h"
Servo serwo;

RC5 rc5(TSOP_PIN);
byte address;
byte command;
byte toggle;

unsigned long currentMillis = 0;
static unsigned long previousMillis = 0;

unsigned long distance = 0;
int actualSpeed = START_SPEED;

RobotState currentState = Idle;

void setup() {
  pinMode(L_DIR, OUTPUT);
  pinMode(R_DIR, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  pinMode(R_PWM, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  serwo.attach(SERWO_PIN);
  serwo.write(START_SERVO);
  Serial.begin(9600);
}

void loop() {

  currentMillis = millis();

  if (rc5.read(&toggle, &address, &command)) {
    handleCommand(command);
  }

  switch (currentState) {
    case Idle:
      // Robot does nothing
      break;

    case MovingForward:
      MoveForward();
      break;

    case MovingForwardRight:
      MoveForwardRight();
      break;

    case MovingForwardLeft:
      MoveForwardLeft();
      break;

    case MovingBackwardLeft:
      MoveBackwardLeft();
      break;

    case MovingBackwardRight:
      MoveBackwardRight();
      break;

    case MovingBackward:
      MoveBackward();
      break;

    case TurningRight:
      TurnRight();
      break;

    case TurningLeft:
      TurnLeft();
      break;

    case Stopping:
      stopMotors();
      currentState = Idle;
      break;

    case Beep:
      digitalWrite(BUZZER, HIGH);
      delay(300);
      digitalWrite(BUZZER, LOW);
      break;

    case searchObstacle:

      if (MesureDistance() > 40) {
        MoveForward();
      } else currentState = TurnSensorRight;
      break;

    case TurnSensorRight:

      stopMotors();
      serwo.write(20);
      delay(800);
      currentState = CheckIfObstacleRight;
      break;

    case CheckIfObstacleRight:

      distance = MesureDistance();
      if (distance > 40) {
        TurnRight();
        delay(400);
        serwo.write(START_SERVO);
        delay(100);
        currentState = searchObstacle;
      } else currentState = TurnSensorLeft;
      break;

    case TurnSensorLeft:

      serwo.write(150);
      delay(800);
      currentState = CheckIfObstacleLeft;
      break;

    case CheckIfObstacleLeft:

      if (MesureDistance() > 40) {
        TurnLeft();
        delay(400);
        currentState = searchObstacle;
      } else {
        digitalWrite(BUZZER, HIGH);
        MoveBackward();
        delay(700);
        TurnRight();
        delay(600);
        digitalWrite(BUZZER, LOW);
        currentState = searchObstacle;
      }
      serwo.write(START_SERVO);
      delay(100);
      break;

    case LineFollow:
      LineFollowing();
      break;
  }
}

void handleCommand(byte cmd) {
  switch (cmd) {
    case 1:
      currentState = MovingForwardLeft;
      break;

    case 2:  
      currentState = MovingForward;
      break;

    case 3:
      currentState = MovingForwardRight;
      break;

    case 4:  
      currentState = TurningLeft;
      break;

    case 5:  
      currentState = Stopping;
      break;

    case 6: 
      currentState = TurningRight;
      break;

    case 7:
      currentState = MovingBackwardLeft;
      break;

    case 8: 
      currentState = MovingBackward;
      break;

    case 9:
      currentState = MovingBackwardRight;
      break;

    case 12:
      currentState = Beep;
      break;

    case 0:  
      currentState = searchObstacle;
      break;
    case 16:  
      currentState = LineFollow;
      break;
    case 32:
      if (actualSpeed < 95)
        actualSpeed += 5;
      break;

    case 33:
      if (actualSpeed > 35)
        actualSpeed -= 5;
      break;
  }
}

void MoveForward(byte speedLeftMotor, byte speedRightMotor) {
  leftMotor(speedLeftMotor);
  rightMotor(speedRightMotor);
}

void MoveForwardRight(byte speedLeftMotor, byte speedRightMotor) {
  leftMotor(speedLeftMotor);
  rightMotor(speedRightMotor - DIFFERENCE_SPEED);
}

void MoveForwardLeft(byte speedLeftMotor, byte speedRightMotor) {
  leftMotor(speedLeftMotor - DIFFERENCE_SPEED);
  rightMotor(speedRightMotor);
}

void MoveBackwardLeft(byte speedLeftMotor, byte speedRightMotor) {
  leftMotor(-speedLeftMotor + DIFFERENCE_SPEED);
  rightMotor(-speedRightMotor);
}

void MoveBackwardRight(byte speedLeftMotor, byte speedRightMotor) {
  leftMotor(-speedLeftMotor);
  rightMotor(-speedRightMotor + DIFFERENCE_SPEED);
}

void MoveBackward(byte speedLeftMotor, byte speedRightMotor) {
  leftMotor(-speedLeftMotor);
  rightMotor(-speedRightMotor);
}

void TurnLeft(byte speedLeftMotor, byte speedRightMotor) {
  leftMotor(-speedLeftMotor);
  rightMotor(speedRightMotor);
}

void TurnRight(byte speedLeftMotor, byte speedRightMotor) {
  leftMotor(speedLeftMotor);
  rightMotor(-speedRightMotor);
}

void stopMotors() {
  analogWrite(L_PWM, 0);  //Turn off left engine
  analogWrite(R_PWM, 0);  //Turn off right engine
}

void LineFollowing() {
  if (leftSensor() == 1 && rightSensor() == 1) {  //Both sensor spot line
    leftMotor(40);                                //Go ahead
    rightMotor(40);
  } else if (leftSensor() == 0) {  //Left sensor does not see line
    leftMotor(40);                 //Driving around a curve to the right
    rightMotor(10);
  } else if (rightSensor() == 0) {  //Right sensor does not see line
    leftMotor(10);                  //Driving around a curve to the left
    rightMotor(40);
  }
}

boolean leftSensor() {
  if (analogRead(L_LINE_SENSOR) > BORDER) {  //If the sensor sees lines
    return 1;                                
  } else {                                   ///If the sensor doesnt see lines
    return 0;                            
  }
}

boolean rightSensor() {
  if (analogRead(R_LINE_SENSOR) > BORDER) {  
    return 1;                                
  } else {                                 
    return 0;                             
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////

int MesureDistance() {

  long robotTime, distance;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 50) {
    previousMillis = currentMillis;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    robotTime = pulseIn(echoPin, HIGH);
    distance = robotTime / 58;
    Serial.println(distance);
    return distance;
  }
  return 50;
}

void leftMotor(int V) {
  if (V > 0) {  
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(L_DIR, 0); 
    analogWrite(L_PWM, V);  
  } else {
    V = abs(V);  
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(L_DIR, 1);  
    analogWrite(L_PWM, V);   
  }
}

void rightMotor(int V) {
  if (V > 0) {  
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(R_DIR, 0); 
    analogWrite(R_PWM, V);  
  } else {
    V = abs(V);  
    V = map(V, 0, 100, 0, PWM_MAX);
    digitalWrite(R_DIR, 1);  
    analogWrite(R_PWM, V);   
  }
}
