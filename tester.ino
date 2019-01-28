#include <SunFounder_PCA9685.h>

#define SERVOMIN  500 
#define SERVOMAX  2500 
#define MIN1 50
#define MAX1 150
#define MIN2 20
#define MAX2 160
#define NORM 90

PCA9685 pwm = PCA9685(0x40);

int servo1_chn = 8;
int servo2_chn = 9;
int servo3_chn = 2;
int servo4_chn = 3;
int servo5_chn = 4;
int servo6_chn = 5;
int servo7_chn = 6;
int servo8_chn = 7;

void setup() {
  Serial.begin(9600);

  pwm.begin();
  Serial.print("begin  ");
  pwm.setFreq(50);
  // setServo(_min_pulse_width, _max_pulse_width), check them on the servo datasheet
  pwm.setServo(SERVOMIN, SERVOMAX);
/*
  pwm.angleWrite(servo1_chn,90);
  pwm.angleWrite(servo2_chn,90);
  pwm.angleWrite(servo3_chn,180);
  pwm.angleWrite(servo4_chn,90);
  pwm.angleWrite(servo5_chn,180);
  pwm.angleWrite(servo6_chn,0);
  pwm.angleWrite(servo7_chn,180);
  pwm.angleWrite(servo8_chn,0);
  delay(200);
  Serial.println("angle 90");
*/}

void goto_pos(int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8)
{
  pwm.angleWrite(servo5_chn,n5);
  delay(20);
  pwm.angleWrite(servo6_chn,n6);
  delay(20);
  pwm.angleWrite(servo7_chn,n7);
  delay(20);
  pwm.angleWrite(servo8_chn,n8);
  delay(20);
  pwm.angleWrite(servo1_chn,n1);
  delay(20);
  pwm.angleWrite(servo2_chn,n2);
  delay(20);
  pwm.angleWrite(servo3_chn,n3);
  delay(20);
  pwm.angleWrite(servo4_chn,n4);
  delay(20);
}
void normal()
{
  goto_pos(NORM,NORM,NORM,NORM,NORM,NORM,NORM,NORM);
  Serial.println("Normalizing...\n");
  delay(100);
}
void sit()
{
  goto_pos(NORM,NORM,NORM,NORM,MAX1,MIN1,MAX1,MIN1);
  Serial.println("Sitting\n");
  delay(100);
}
void stand()
{
  goto_pos(NORM,NORM,NORM,NORM,MIN1,MAX1,MIN1,MAX1);
  Serial.println("Standing\n");
  delay(100);
}
void look_r()
{  
  goto_pos(MIN2,MIN2,MIN2,MIN2,NORM,NORM,NORM,NORM);
  Serial.println("Looking Rignt\n");
  delay(700);
}
void look_l()
{
  goto_pos(MAX2,MAX2,MAX2,MAX2,NORM,NORM,NORM,NORM);
  Serial.println("Looking Rignt\n");
  delay(700);
}
void turn_r()
{ 
  goto_pos(MIN2,MIN2,MIN2,MIN2,NORM,NORM,NORM,NORM);
  delay(100);
  goto_pos(NORM,MIN2,NORM,MIN2,MAX1,NORM,MAX1,NORM);
  delay(100);
  goto_pos(NORM,NORM,NORM,NORM,NORM,MIN1,NORM,MIN1);
  delay(100);
  normal();
  Serial.println("Turning Right");
}
void turn_l()
{ 
  goto_pos(MAX2,MAX2,MAX2,MAX2,NORM,NORM,NORM,NORM);
  delay(100);
  goto_pos(NORM,MAX2,NORM,MAX2,MAX1,NORM,MAX1,NORM);
  delay(100);
  goto_pos(NORM,NORM,NORM,NORM,NORM,MIN1,NORM,MIN1);
  delay(100);
  normal();
  Serial.println("Turning Left");
  delay(100);
}
void defence_h()
{
  goto_pos(NORM+45,NORM-45,NORM+45,NORM-45,NORM,NORM,NORM,NORM);
  Serial.println("Defence Position Horizontal");
  delay(300);
}
void defence_v()
{
  goto_pos(NORM-45,NORM+45,NORM-45,NORM+45,NORM,NORM,NORM,NORM);
  Serial.println("Defence Position Vetical");
  delay(300);
}
void forward()
{
  goto_pos(NORM,NORM-45,NORM+45,NORM,NORM,NORM,MIN1,NORM);
  delay(300);
  goto_pos(NORM,NORM,NORM+45,NORM,NORM,MIN1,NORM,NORM);
  delay(300);
  goto_pos(NORM+45,NORM-10,NORM,NORM+10,NORM+30,NORM-30,NORM+30,NORM-30);
  delay(300);
  goto_pos(NORM+45,NORM,NORM,NORM-45,NORM,NORM,NORM,MAX1);
  delay(300);
  goto_pos(NORM-10,NORM,NORM,NORM-45,MAX1,NORM,NORM,NORM);
  delay(300);
  goto_pos(NORM+10,NORM-45,NORM-10,NORM,NORM-10,MAX1,MAX1,NORM-10);
  delay(300);
}
void bow_right()
{
  goto_pos(NORM+45,NORM-45,NORM+45,NORM-45,MIN1,MIN1,MAX1,MAX1);
  Serial.println("Bowing Right");
  delay(700);
}
void bow_left()
{
  goto_pos(NORM+45,NORM-45,NORM+45,NORM-45,MAX1,MAX1,MIN1,MIN1);
  Serial.println("Bowing left");
  delay(700);
}
void bow_forward()
{
  goto_pos(NORM+45,NORM-45,NORM+45,NORM-45,MAX1,MIN1,MIN1,MAX1);
  Serial.println("Bowing left");
  delay(150);
}
void bow_backward()
{
  goto_pos(NORM+45,NORM-45,NORM+45,NORM-45,MIN1,MAX1,MAX1,MIN1);
  Serial.println("Bowing left");
  delay(150);
}
void hi()
{ 
  goto_pos(NORM-45,MAX2,MAX2,NORM-45,NORM,MAX1,MIN1,MAX1);
  delay(250);
  goto_pos(NORM+45,MAX2,MAX2,NORM-45,MAX1,MAX1,MIN1,MAX1);
  delay(250);
  goto_pos(NORM-45,MAX2,MAX2,NORM-45,MAX1,MAX1,MIN1,MAX1);
  delay(250);
  goto_pos(NORM+45,MAX2,MAX2,NORM-45,NORM,MAX1,MIN1,MAX1);
  delay(250);
  goto_pos(NORM-45,MAX2,MAX2,NORM-45,NORM,MAX1,MIN1,MAX1);
  delay(250);
  goto_pos(NORM+45,MAX2,MAX2,NORM-45,MAX1,MAX1,MIN1,MAX1);
  delay(250);
  goto_pos(NORM,NORM+45,NORM+45,NORM-45,MIN1,MAX1,MIN1,MAX1);
  delay(100);
  Serial.println("Hi!");
}



void f()
{
  goto_pos(90,45,135,90,180,0,180,0);
  delay(200);
  goto_pos(90,90,135,90,180,45,180,0);
  delay(200);
  goto_pos(135,90,90,110,180,0,180,20);
  delay(200);
  goto_pos(135,90,90,45,180,0,180,0);
  delay(200);
  goto_pos(90,90,90,45,135,0,180,0);
  delay(200);
  goto_pos(90,45,60,90,180,0,160,0);
  delay(200);
}




void loop() {
  //defence_v();
  //defence_h();
  //look_r();
  //look_l();
  //sit();
  //stand();
  //forward();
  //backward();
  //turn_r();
  //turn_l();
  bow_right();
  //bow_left();
  //bow_forward();
  //bow_backward();
  //normal();
  //hi();
  //f();
/*
pwm.angleWrite(servo3_chn,90);
  delay(400);
pwm.angleWrite(servo3_chn,180);
  delay(400);
*/


}
