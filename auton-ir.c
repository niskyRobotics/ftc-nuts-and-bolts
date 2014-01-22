#pragma config(Sensor, S3,     irRight,        sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     irLeft,         sensorHiTechnicIRSeeker1200)
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
// AUTONOMOUS IR, currently BROKEN (but will fix)

task main()
{

  waitForStart();

motor[Left] =  154;
motor[Right] = 154;
wait1Msec(500);	//drive up to baskets

motor[Left] = 154;
motor[Right] = -154;
wait1Msec(450);
motor[Left] = 0;
motor[Right] = 0;	//turn counter clockwise to face parallel to baskets

if(SensorValue[irRight] !=5)	//if the ir beacon is not directly infront of ir sensor
{
motor[Left] = 154;
motor[Right] = 154;	//move forward to rest of baskets
}
else	//if ir sensor is directly infront of ir sensor
{
motor[Left] = 154;
  motor[Right] = -154;
wait1Msec(450);
motor[Left] = 0;
motor[Right] = 0;	//turn to face basket

motor[Arm] = 154;
wait1Msec(3200);	
motor[Arm] = 0;	//raise arm

motor[Left] = 154;
  motor[Right] = 154;
wait1Msec(400);	
motor[Left] = 0;
motor[Right] = 0;	//drive closer to basket so that bucket is derectly of bascket

motor[Arm] = 154;
wait1Msec(1200);
motor[Arm] = 0;	//rais arm to drop block into basket
}
}