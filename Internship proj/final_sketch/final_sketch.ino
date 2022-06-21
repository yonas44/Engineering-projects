
#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);

int i = 0;
int j = 0;
int spdA[4] = {125,150,175,200};
int spdB[4] = {175,200,225,255};
int spd = spdA[0];
int spdd = spdB[0];
char command;

void setup()
{
  Serial.begin(9600);  
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); 
    switch (command) {
      case '+':
        fast();
        break;
      case '-':
        slow();
        break;
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
        case 'T':
        rst();
        break;
        case '>':
        fast2();
        break;
        case '<':
        slow2();
        break;
    }
  }
}
void fast() 
{
  if(i < 3) {
    i++;
  spd = spdA[i];
  }
}

void slow()
{
  if(i > 0) {
    i--;
    spd = spdA[i];
  }
}

void fast2() 
{
  if(j < 3) {
    j++;
    spdd = spdB[j];
  }
}

void slow2()
{
  if(j > 0) {
    j--;
    spdd = spdB[j];
  }
}

void forward()
{
  motor1.setSpeed(spd); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(spd); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(spdd);
  motor3.run(FORWARD); 

}

void back()
{
  motor1.setSpeed(spd); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(spd); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(spdd); 
  motor3.run(RELEASE); 

}

void left()
{
  motor1.setSpeed(spd); 
  motor1.run(BACKWARD); 
  motor2.setSpeed(spd); 
  motor2.run(RELEASE); 
  motor3.setSpeed(spdd); 
  motor3.run(RELEASE);  

}

void right()
{
  motor1.setSpeed(spd); 
  motor1.run(RELEASE); 
  motor2.setSpeed(spd); 
  motor2.run(BACKWARD); 
  motor3.setSpeed(spdd); 
  motor3.run(RELEASE); 

}

void Stop()
{
  motor1.setSpeed(0); 
  motor1.run(RELEASE); 
  motor2.setSpeed(0); 
  motor2.run(RELEASE); 
  motor3.setSpeed(0); 
  motor3.run(RELEASE); 

}

void rst()
{
  i = 0;
  j = 0;
  spd = spdA[0];
  spdd = spdB[0];
}

