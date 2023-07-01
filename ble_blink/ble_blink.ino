#include <AFMotor.h>
                          //_________
AF_DCMotor motor1(1);     //| 1   2 |
AF_DCMotor motor2(2);     //|       |
AF_DCMotor motor3(3);     //|       |
AF_DCMotor motor4(4);     //| 3   4 |
                          //¯¯¯¯¯¯¯¯¯
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  //pinMode(A1, OUTPUT);
  //pinMode(A2, OUTPUT);
  //pinMode(A3, OUTPUT);
  //pinMode(A4, OUTPUT);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char data = Serial.read();
    switch (data) {
      case 'F': 
        //analogWrite(A0, 200);
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        motor3.run(FORWARD);
        motor4.run(FORWARD); 
        break;
      case 'B': 
        //analogWrite(A1, 200);
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        motor3.run(BACKWARD);
        motor4.run(BACKWARD);
        break;
      case 'L': 
        //analogWrite(A2, 200);
        motor1.run(FORWARD);
        motor3.run(FORWARD);
        break;
      case 'R': 
        //analogWrite(A3, 200);
        motor2.run(FORWARD);
        motor4.run(FORWARD);
        break;
      case 'H': 
        analogWrite(A0, 200);
        break;
      default: 
        break;
    }
    Serial.println(data);
  }
}
