#ifndef ROBOT_CONTROL_H
#define ROBOT_CONTROL_H

#include <Arduino.h>
#include <Servo.h>
#include <RC5.h>

#define SERWO_PIN 11

#define L_PWM 5
#define L_DIR 4
#define R_PWM 6
#define R_DIR 9
#define PWM_MAX 165

#define BUZZER 10
#define LED 13
#define TSOP_PIN 3

#define trigPin 7
#define echoPin 8

#define START_SPEED 40
#define DIFFERENCE_SPEED 20
#define START_SERVO 80

#define BORDER 900
#define R_LINE_SENSOR A0
#define L_LINE_SENSOR A1

extern int actualSpeed;

enum RobotState {
  Idle,
  MovingForward,
  MovingForwardRight,
  MovingForwardLeft,
  MovingBackwardLeft,
  MovingBackwardRight,
  MovingBackward,
  TurningRight,
  TurningLeft,
  Stopping,
  Beep,
  searchObstacle,  //13
  TurnSensorRight,
  CheckIfObstacleRight,
  TurnSensorLeft,
  CheckIfObstacleLeft,
  LineFollow
};

void handleCommand(byte cmd);
void MoveForward(byte speedLeftMotor = actualSpeed, byte speedRightMotor = actualSpeed);
void MoveForwardRight(byte speedLeftMotor = actualSpeed, byte speedRightMotor = actualSpeed);
void MoveForwardLeft(byte speedLeftMotor = actualSpeed, byte speedRightMotor = actualSpeed);
void MoveBackward(byte speedLeftMotor = actualSpeed, byte speedRightMotor = actualSpeed);
void MoveBackwardLeft(byte speedLeftMotor = actualSpeed, byte speedRightMotor = actualSpeed);
void MoveBackwardRight(byte speedLeftMotor = actualSpeed, byte speedRightMotor = actualSpeed);
void TurnLeft(byte speedLeftMotor = actualSpeed, byte speedRightMotor = actualSpeed);
void TurnRight(byte speedLeftMotor = actualSpeed, byte speedRightMotor = actualSpeed);
void stopMotors();
void leftMotor(int V);  // do zmiany
void rightMotor(int V);
int MesureDistance();
void LineFollowing();
boolean leftSensor();
boolean rightSensor();

#endif // ROBOT_CONTROL_H
