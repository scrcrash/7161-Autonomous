#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     IRSensor,       sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorTR,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorBR,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorTL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorBL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     motorBrush,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorConveyor, tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servoHingeL,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servoHingeR,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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

//void turnDegrees(int degree, int speed)
//{
//	motor[motorBR] = -speed; //turn both motors on at 30 percent power
//  motor[motorBL] = speed;
//  motor[motorTR] = -speed;
//  motor[motorTL] = speed;

//  wait1Msec(500);

//	motor[motorBR] = 0; //turn both motors off
//	motor[motorBL] = 0;
//	motor[motorTR] = 0;
//	motor[motorTL] = 0;
//}

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

void findIrRamp()
{
	//Goes forward certain distance looking for IR. If doesn't find IR, turns slightly, continues on and looks for IR. If doesn't find it, turns slightly and continues
	while(SensorValue[IRSensor] == 0) //while it doesn't find any IR signal, go forward __ inches
	{
		//Variables
		int tickGoal;
		int tickTest = nMotorEncoder[motorBR];

		//reset encoders
		nMotorEncoder[motorTR] = 0;
		nMotorEncoder[motorTL] = 0;
		nMotorEncoder[motorBR] = 0;
		nMotorEncoder[motorBL] = 0;

		tickGoal = 67 * inch; //change value later

		//move forward until encoder reading is more than the goal
		while(tickTest < tickGoal)
		{
			motor[motorTL] = speed;
			motor[motorTR] = speed;
			motor[motorBL] = speed;
			motor[motorBR] = speed;

			tickTest = nMotorEncoder[motorBR];
		}

		//reset encoders
		nMotorEncoder[motorTR] = 0;
		nMotorEncoder[motorTL] = 0;
		nMotorEncoder[motorBR] = 0;
		nMotorEncoder[motorBL] = 0;

		tickGoal = 67 * inch; //change value later

		//turn slightly FIND VALUE LATER
		while(tickTest < tickGoal)
		{
			motor[motorTL] = speed * -1;
			motor[motorTR] = speed;
			motor[motorBL] = speed * -1;
			motor[motorBR] = speed;

			tickTest = nMotorEncoder[motorBR];
		}

		//reset encoders
		nMotorEncoder[motorTR] = 0;
		nMotorEncoder[motorTL] = 0;
		nMotorEncoder[motorBR] = 0;
		nMotorEncoder[motorBL] = 0;

		tickGoal = 67 * inch; //change value later

		//go forward again
		while(tickTest < tickGoal)
		{
			motor[motorTL] = speed;
			motor[motorTR] = speed;
			motor[motorBL] = speed;
			motor[motorBR] = speed;

			tickTest = nMotorEncoder[motorBR];
		}

		//reset encoders
		nMotorEncoder[motorTR] = 0;
		nMotorEncoder[motorTL] = 0;
		nMotorEncoder[motorBR] = 0;
		nMotorEncoder[motorBL] = 0;

		tickGoal = 67 * inch; //change value later

		//turn slightly FIND VALUE LATER
		while(tickTest < tickGoal)
		{
			motor[motorTL] = speed * -1;
			motor[motorTR] = speed;
			motor[motorBL] = speed * -1;
			motor[motorBR] = speed;

			tickTest = nMotorEncoder[motorBR];
		}



	}

	motor[motorTL] = 0;
	motor[motorTR] = 0;
	motor[motorBL] = 0;
	motor[motorBR] = 0;

}

void gripGoal()
{
	//Bring the grips down
	servo[servoHingeL] = 90; //CHANGE VALUES LATER
	servo[servoHingeR] = 90;

	//Grip tightens around the goal
	//servo[servoGripL] = 100; //CHANGE VALUES LATER
	//servo[servoGripR] = 0;
}

void ungripGoal()
{
	//Grip loosens around the goal
	//servo[servoGripL] = 0; //CHANGE VALUES LATER
	//servo[servoGripR] = 100;
}

task main()
{
	//goInches(17, 60);
	//turnRightDegrees(90, 60);
	//turnLeftDegrees(90, 40);

	//Center goal in position 2
	if(SensorValue[IRSensor] == )
	{
		turnLeftDegrees();
		goInches(8, 60);
		turnLeftDegrees();
		goInches(5, 60);
	}

	//Center goal in position 3
	else if(SensorValue[IRSensor] == )
	{
		//hit kickstand first
		goInches() //forward to hit kickstand
		goInches() //backward to hit kickstand

		//find IR
		turnLeftDegrees();
		goInches(8, 60);
		turnLeftDegrees();
		goInches(20, 60);
		turnLeftDegrees();
		goInches();

}

//1440 ticks per revolution
//4 inch diameter wheel
//12.56 inch circumference
//1440 / 12.56 = 114.6 ticks per inch

//1120 / 12.56 = 89.17 ticks per inch
