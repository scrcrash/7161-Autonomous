#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     IRSensor,       sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorBL,       tmotorTetrix, openLoop, driveRight)
#pragma config(Motor,  mtr_S1_C1_2,     motorBR,       tmotorTetrix, openLoop, reversed, driveLeft)
#pragma config(Motor,  mtr_S1_C2_1,     motorTR,       tmotorTetrix, openLoop, reversed, driveRight, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorTL,       tmotorTetrix, openLoop, driveLeft, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorPulley,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     motorb,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     motora,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     motorBrush,    tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S3_C1_1,    servoHingeL,          tServoStandard)
#pragma config(Servo,  srvo_S3_C1_2,    servoHingeR,          tServoStandard)
#pragma config(Servo,  srvo_S3_C1_3,    servoBasket,          tServoStandard)
#pragma config(Servo,  srvo_S3_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C1_6,    servoBlocker,         tServoStandard)

/* TASKS TO DO
	1. Go
*/
void turnLeftDegrees(int degree)
{
	int tickGoal = degree * 8;
	int tickTest = nMotorEncoder[motorBL];

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

		tickTest = abs(nMotorEncoder[motorBL]);

	}
}

void turnRightDegrees(int degree)
{
	int tickGoal = degree * 8;
	int tickTest = nMotorEncoder[motorBL];

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

		tickTest = nMotorEncoder[motorBL];
	}
}

void goInches(int inch, int speed)
{
	//reset encoders
	nMotorEncoder[motorTR] = 0;
	nMotorEncoder[motorTL] = 0;
	nMotorEncoder[motorBR] = 0;
	nMotorEncoder[motorBL] = 0;

	int tickGoal = 67 * inch;
	int tickTest = 0;

	//move forward until encoder reading is more than the goal
	while(tickTest < tickGoal)
	{
		motor[motorTL] = speed;
		motor[motorTR] = speed;
		motor[motorBL] = speed;
		motor[motorBR] = speed;

		tickTest = nMotorEncoder[motorBL];
	}
}

void goBackInches(int inch, int speed)
{

	//reset encoders
	nMotorEncoder[motorTR] = 0;
	nMotorEncoder[motorTL] = 0;
	nMotorEncoder[motorBR] = 0;
	nMotorEncoder[motorBL] = 0;

	int tickGoal = 67 * inch;
	int tickTest = 0;

	//move forward until encoder reading is more than the goal
	while(tickTest < tickGoal)
	{
		motor[motorTL] = -speed;
		motor[motorTR] = -speed;
		motor[motorBL] = -speed;
		motor[motorBR] = -speed;

		tickTest = abs(nMotorEncoder[motorBL]);

	}
		motor[motorTL] = 0;
		motor[motorTR] = 0;
		motor[motorBL] = 0;
		motor[motorBR] = 0;
}
task main()
{
turnLeftDegrees(65);
goInches(25,70);
wait1Msec(50);
turnRightDegrees(110);
}
