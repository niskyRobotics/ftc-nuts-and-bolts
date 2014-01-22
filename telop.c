#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  none,     none,     none)
#pragma config(Motor,  mtr_S1_C1_1,     Spinners,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     FlagMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorF,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     Arm,           tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     Left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     Right,         tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C1_1,    FlagServo,            tServoStandard)


#include "JoystickDriver.c"
task main()
{
 	 waitForStart();

while(true)
{

motor[Right] = joystick.joy1_y1;
motor[Left] = joystick.joy1_y2;
if(joy1Btn(2) == 1 || joy2Btn(2) == 1)
{
motor[Arm] = 154;
}
if(joy1Btn(3) == 1 || joy2Btn(3) == 1)
{
motor[Arm] = -154;
}
if(joy1Btn(2) == 0 && joy1Btn(3) == 0 && joy2Btn(2) == 0 && joy2Btn(3) == 0)
{
motor[Arm] = 0;
}
if(joy1Btn(5) == 1)
  {
  motor[Spinners] = 100;
}
  if(joy1Btn(6) == 1)
  {
  motor[Spinners] = -100;
  }
 	if(joy1Btn(5) == 0 && joy1Btn(6) == 0)
{
  motor[Spinners] = 0;
  }
  if(joy1Btn(4) == 1)
 	{
 	servo[FlagServo] = 150;
 	}
 	if(joy1Btn(1) == 1)
 	{
 	servo[FlagServo] = -255;
 	}
 	if(joy1Btn(7) == 1)
  {
  motor[FlagMotor] = 154;
}
  if(joy1Btn(8) == 1)
  {
  motor[FlagMotor] = -154;
  }
 	if(joy1Btn(8) == 0 && joy1Btn(7) == 0)
{
  motor[FlagMotor] = 0;
}
}
}