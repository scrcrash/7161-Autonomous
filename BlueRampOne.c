#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     IRSensor,       sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorTL,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorBL,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorTR,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorBR,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorBrush,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorConveyor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     motorPulley,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     motorK,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servoHingeL,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servoGripL,           tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servoHingeR,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    servoGripR,           tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servoBasket,          tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*	1. Go to the Center Goal
	2. Find the IR Beacon
	3. Score ball
	4. Go to Kickstand
	5. Hit Kickstand
*/

void turnLeftDegrees(int degree)
{
	int tickGoal = degree * 8;
	int tickTest = nMotorEncoder[motorTR];

	//reset encoders
	nMotorEncoder[motorTR] = 0;
	nMotorEncoder[motorTL] = 0;
	nMotorEncoder[motorBR] = 0;
	nMotorEncoder[motorBL] = 0;

	//move forward until encoder reading is more than the goal
	while(tickTest < tickGoal)
	{
		motor[motorTL] = -60;
		motor[motorTR] = 60;
		motor[motorBL] = -60;
		motor[motorBR] = 60;

		tickTest = nMotorEncoder[motorTR];
	}
}

void turnRightDegrees(int degree)
{
	int tickGoal = degree * 8;
	int tickTest = nMotorEncoder[motorTL];

	//reset encoders
	nMotorEncoder[motorTR] = 0;
	nMotorEncoder[motorTL] = 0;
	nMotorEncoder[motorBR] = 0;
	nMotorEncoder[motorBL] = 0;

	//move forward until encoder reading is more than the goal
	while(tickTest < tickGoal)
	{
		motor[motorTL] = 60;
		motor[motorTR] = -60;
		motor[motorBL] = 60;
		motor[motorBR] = -60;

		tickTest = nMotorEncoder[motorTL];
	}
}

void goInches(int inch, int speed)
{
	int tickGoal = 67 * inch;
	int tickTest = nMotorEncoder[motorBR];

	//reset encoders
	nMotorEncoder[motorTR] = 0;
	nMotorEncoder[motorTL] = 0;
	nMotorEncoder[motorBR] = 0;
	nMotorEncoder[motorBL] = 0;

	//move forward until encoder reading is more than the goal
	while(tickTest < tickGoal)
	{
		motor[motorTL] = speed;
		motor[motorTR] = speed;
		motor[motorBL] = speed;
		motor[motorBR] = speed;

		tickTest = nMotorEncoder[motorBR];
	}
}
void gripGoal()
{
	//Bring the grips down
	servo[servoHingeL] = 0; //CHANGE VALUES LATER
	servo[servoHingeR] = 255;

	//Grip tightens around the goal
	//servo[servoGripL] = 100; //CHANGE VALUES LATER
	//servo[servoGripR] = 0;
}

void ungripGoal()
{
	//Grip loosens around the goal
	servo[servoHingeL] = 200; //CHANGE VALUES LATER
	servo[servoHingeR] = 55;
}
/* TASKS TO DO- BLUE
	1. Move off of ramp [20 points]
	2. Go to goal
	3. Grab goal
	4. Move goal to parking zone [20 points]
*/

//set robot up backwards
task main()
{
	//move backward off ramp
	goInches(72, -60);
	wait1Msec(500);
	//adjust using compass?

	//move backward again
	goInches(4,-30);

	//score ball in two different goals
	//grip and score from basket in one goal
	gripGoal();
	//turn, move forward and then score in second goal
	//drive to parking zone pushing goal one


}
