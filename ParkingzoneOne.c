#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Hubs,  S3, HTServo,  none,     none,     none)
#pragma config(Sensor, S4,     IRSensor,       sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorBL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorBR,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorTR,       tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorTL,       tmotorTetrix, openLoop, encoder)
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

	//move backward until encoder reading is more than the goal
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

//void kickstand()
//{
//	while(true)
//	{
//		//Kickstand
//		turnRightDegrees(50);
//		//tested to this point
//		goInches(17, 60);
//		turnLeftDegrees(40);
//		goInches(20, 60); //change value
//	}
//}

//void scoreball()
//{
//	motor[motorPulley] = 40;
//	wait1Msec(3000); //change value
//	motor[motorPulley] = 0;

//	servo[servoBasket] = 255; //change value

//}


int Sensor = SensorValue[IRSensor];

task main()
{
//  waitForStart(); // Wait for the beginning of autonomous phase.
while(true)  // infinite loop:
	{
	  nxtDisplayCenteredTextLine(3, "Sensor Value: %d", SensorValue[IRSensor]);  // display "Sensor Value: ##"
	  wait1Msec(50);  // Wait 100 milliseconds to help display correctly
	}
	//initial position
	goInches(27, 70);
	wait1Msec(50);

	if(sensor == 5) //Center goal position 3, IR straight in front
		{
			//move forward
			turnRightDegrees(15);
			wait1Msec(50);

			goInches(5,70);
			wait1Msec(50);

		//Score ball

		//move back to initial position
			//turnRightDegrees(15);
			//wait1Msec(50);

		//goBackInches(10,70);
		//wait1Msec(50);

		//Kickstand
		//turnLeftDegrees(90);
		//wait1Msec(10);
		//turnRightDegrees(900);

		//tested to this point
		//goInches(9, 60);
		//turnLeftDegrees(80);
		//goInches(20, 60); //change value
	//}

	//else //Center goal either in position 2 or 1
	//{
	//	wait1Msec(50);

		//turnLeftDegrees(65);

		//goInches(25,70);
		//wait1Msec(50);

		//turnRightDegrees(110);

		//turnRightDegrees(180);
		//goInches(23, 60);
		//turnRightDegrees(45); //try to find IR. If IR found, position 2
		//if(SensorValue[IRSensor] == 5) //Center goal in position 2
		//{
		//	//Score ball

		//	//Kickstand
		//	turnRightDegrees(50);
		//	goInches(17, 60);
		//	turnLeftDegrees(40);
		//	goInches(20, 60); //change value
		//}
		////Else in position 3
		//else
		//{
		//	turnLeftDegrees(45);
		//	goInches(23, 60);
		//	turnRightDegrees(90);
		//	if(SensorValue[IRSensor] == 5) //Center goal in position 3
		//	{
		//		//Score ball

		//		//Kickstand
		//		turnRightDegrees(50);
		//		goInches(17, 60);
		//		turnLeftDegrees(40);
		//		goInches(20, 60); //change value
		//	}
		//}
//	}
}
