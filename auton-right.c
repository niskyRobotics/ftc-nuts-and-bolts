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
// AUTONOMOUS RIGHT SIDE
task main()
{

  waitForStart();

motor[Arm] = 154;  
wait1Msec(3200);	
motor[Arm] = 0;	//initial Arm raise
motor[Left] =  154;
motor[Right] = 154;
wait1Msec(900);	
motor[Left] =  0;
motor[Right] = 0;	//drive up to basket
motor[Arm] = 154;
wait1Msec(1200);	
motor[Arm] = 0;	//raise arm to drop block into basket
motor[Left] = -154;
motor[Right] = -154;
wait1Msec(700);	
motor[Left] = 0;
motor[Right] = 0;	//back up to prepare to lower arm
motor[Arm] = -154;
wait1Msec(3500);	
motor[Arm] = 0;	//lower arm	
motor[Left] = -154;
motor[Right] = 154;
wait1Msec(450);	//turn clockwise 45 degrees
motor[Left] = 154;
motor[Right] = 154;
wait1Msec(2300);	//drive infront of ramp
motor[Left] = 154;
motor[Right] = -154;
wait1msec(1100);	//turn counterclock wise 90 degrees to face ramp
motor[Left] = 154;
motor[Right] = 154;
wait1Msec(1700);	
motor[Left] = 0;
motor[Right] = 0;	//drive up ramp 
}