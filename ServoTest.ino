  #include <SimpleFOC.h>
  #include <Servo.h>
  
BLDCDriver3PWM driver = BLDCDriver3PWM(PC6,PC7,PC8,PC15,PC15,PC15);
Servo myservo; 
int pos=0;

void setup() {
  
  driverInit();
  myservo.attach(PB10);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void driverInit(){
  driver.voltage_power_supply=8.4;
  driver.pwm_frequency=20;
  driver.voltage_limit=8.4;
  driver.init();
  driver.enable();
  driver.setPwm(0,5,6);
  
  
}
