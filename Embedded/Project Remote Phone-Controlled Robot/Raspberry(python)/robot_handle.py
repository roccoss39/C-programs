import math
import RPi.GPIO as GPIO

L_DIR = 5   
R_DIR = 6  
L_PWM = 12 
R_PWM = 13 

class Robot:
    def __init__(self, l_dir_pin, r_dir_pin, l_pwm_pin, r_pwm_pin, pwm_freq=1000):
        GPIO.setwarnings(False)  
        self.l_dir_pin = l_dir_pin
        self.r_dir_pin = r_dir_pin
        self.l_pwm_pin = l_pwm_pin
        self.r_pwm_pin = r_pwm_pin

        # Inicjalizacja GPIO
        GPIO.setmode(GPIO.BCM)
        GPIO.setup(self.l_dir_pin, GPIO.OUT)
        GPIO.setup(self.r_dir_pin, GPIO.OUT)
        GPIO.setup(self.l_pwm_pin, GPIO.OUT)
        GPIO.setup(self.r_pwm_pin, GPIO.OUT)

        # Inicjalizacja PWM
        self.left_pwm = GPIO.PWM(self.l_pwm_pin, pwm_freq)
        self.right_pwm = GPIO.PWM(self.r_pwm_pin, pwm_freq)
        self.left_pwm.start(0)
        self.right_pwm.start(0)

    def left_motor(self, pwm, direction):
        if direction >= 0: 
            GPIO.output(self.l_dir_pin, GPIO.LOW)
        else: 
            GPIO.output(self.l_dir_pin, GPIO.HIGH)
        self.left_pwm.ChangeDutyCycle(pwm)

    def right_motor(self, pwm, direction):
        if direction >= 0: 
            GPIO.output(self.r_dir_pin, GPIO.LOW)
        else: 
            GPIO.output(self.r_dir_pin, GPIO.HIGH)
        self.right_pwm.ChangeDutyCycle(pwm)

    def set_duty(self, x, y):
        print(f"x: {x}, y: {y}")
        pwm = int(math.sqrt(x**2 + y**2))

        if x >= 0 and y >= 0:
            self.left_motor(pwm, y)
            self.right_motor(y, y)
        elif x < 0 and y >= 0:
            self.left_motor(y, y)
            self.right_motor(pwm, y)
        elif x < 0 and y < 0:
            self.left_motor(abs(y), y)
            self.right_motor(pwm, y)
        else:
            self.left_motor(pwm, y)
            self.right_motor(abs(y), y)

    def stop(self):
        self.left_pwm.stop()
        self.right_pwm.stop()
        GPIO.cleanup()

