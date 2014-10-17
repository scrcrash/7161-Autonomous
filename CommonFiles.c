#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S1,     IRSeeker,       sensorNone)
#pragma config(Sensor, S2,     LightSensor,    sensorLightInactive)
#pragma config(Motor,  mtr_S1_C1_1,     motorTL,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorBL,       tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C2_1,     motorTR,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorBR,       tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C4_1,     motorNothing,  tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorBrush,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servoGrip1,           tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servoGrip2,           tServoStandard)
#pragma config(Servo,  srvo_S1_C3_3,    servoHinge1,          tServoStandard)
#pragma config(Servo,  srvo_S1_C3_4,    servoHinge2,          tServoStandard)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void turnLeftDegrees(int degree, int speed)
{
	//17 ticks per degree
	int tickGoal = 17 * degree;

	nMotorEncoder[motorBR] = 0;  //clear the LEGO motor encoders
  nMotorEncoder[motorBL] = 0;
  nMotorEncoder[motorTR] = 0;
  nMotorEncoder[motorTL] = 0;

  nMotorEncoderTarget[motorBR] = tickGoal; //set the target stoping position
  nMotorEncoderTarget[motorBL] = tickGoal;
  nMotorEncoderTarget[motorTR] = tickGoal;
  nMotorEncoderTarget[motorTL] = tickGoal;

  motor[motorBR] = speed; //turn both motors on at 30 percent power
  motor[motorBL] = speed * -1;
  motor[motorTR] = speed;
  motor[motorTL] = speed * -1;

  while (nMotorRunState[motorBR] != runStateIdle || nMotorRunState[motorBL] != runStateIdle ||
  			 nMotorRunState[motorTR] != runStateIdle || nMotorRunState[motorTL] != runStateIdle) //while the encoder wheel turns one revolution
  {
    // This condition waits for motors B + C to come to an idle position. Both motors stop
    // and then jumps out of the loop
  }

  motor[motorBR] = 0; //turn both motors off
  motor[motorBL] = 0;
  motor[motorTR] = 0;
  motor[motorTL] = 0;

  wait1Msec(3000);  // wait 3 seconds to see feedback on the debugger screens
                    // open the "NXT Devices" window to see the distance the encoder spins.
                    // the robot will come to a stop at the nMotorEncoderTarget position.
}

void turnRightDegrees(int degree, int speed)
{
	//17 ticks per degree
	int tickGoal = 17 * degree;

	nMotorEncoder[motorBR] = 0;  //clear the LEGO motor encoders
  nMotorEncoder[motorBL] = 0;
  nMotorEncoder[motorTR] = 0;
  nMotorEncoder[motorTL] = 0;

  nMotorEncoderTarget[motorBR] = tickGoal; //set the target stoping position
  nMotorEncoderTarget[motorBL] = tickGoal;
  nMotorEncoderTarget[motorTR] = tickGoal;
  nMotorEncoderTarget[motorTL] = tickGoal;

  motor[motorBR] = speed * -1; //turn both motors on at 30 percent power
  motor[motorBL] = speed;
  motor[motorTR] = speed * -1;
  motor[motorTL] = speed;

  while (nMotorRunState[motorBR] != runStateIdle || nMotorRunState[motorBL] != runStateIdle ||
  			 nMotorRunState[motorTR] != runStateIdle || nMotorRunState[motorTL] != runStateIdle) //while the encoder wheel turns one revolution
  {
    // This condition waits for motors B + C to come to an idle position. Both motors stop
    // and then jumps out of the loop
  }

  motor[motorBR] = 0; //turn both motors off
  motor[motorBL] = 0;
  motor[motorTR] = 0;
  motor[motorTL] = 0;

  wait1Msec(100);  // wait 3 seconds to see feedback on the debugger screens
                    // open the "NXT Devices" window to see the distance the encoder spins.
                    // the robot will come to a stop at the nMotorEncoderTarget position.
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
	int tickGoal = 115 * inch;
	nMotorEncoder[motorBR] = 0;  //clear the LEGO motor encoders
  nMotorEncoder[motorBL] = 0;
  nMotorEncoder[motorTR] = 0;
  nMotorEncoder[motorTL] = 0;

  nMotorEncoderTarget[motorBR] = tickGoal; //set the target stoping position
  nMotorEncoderTarget[motorBL] = tickGoal;
  nMotorEncoderTarget[motorTR] = tickGoal;
  nMotorEncoderTarget[motorTL] = tickGoal;

  motor[motorBR] = speed; //turn both motors on at 30 percent power
  motor[motorBL] = speed;
  motor[motorTR] = speed;
  motor[motorTL] = speed;

  while (nMotorRunState[motorBR] != runStateIdle || nMotorRunState[motorBL] != runStateIdle ||
  			 nMotorRunState[motorTR] != runStateIdle || nMotorRunState[motorTL] != runStateIdle) //while the encoder wheel turns one revolution
  {
    // This condition waits for motors B + C to come to an idle position. Both motors stop
    // and then jumps out of the loop
  }

  motor[motorBR] = 0; //turn both motors off
  motor[motorBL] = 0;
  motor[motorTR] = 0;
  motor[motorTL] = 0;

  wait1Msec(100);  // wait 3 seconds to see feedback on the debugger screens
                    // open the "NXT Devices" window to see the distance the encoder spins.
                    // the robot will come to a stop at the nMotorEncoderTarget position.
}

void findIr() //Using light sensor
//The darker the environment, the higher the value will be
{
	while(SensorValue[IRSeeker] != 5) //While the IR sensor hasn't been found
	{
		while(SensorValue[LightSensor] > 60) //change value later. If the light sensor reads grey (the main floor), turn until it finds yellow
		{
			motor[motorBR] = -15;
			motor[motorBL] = 15;
			motor[motorTR] = -15;
			motor[motorTL] = 15;
		}
		//If the light sensor does read yellow, go forward very slowly to try and find the IR sensor
		motor[motorBR] = 15;
		motor[motorTR] = 15;
		motor[motorBL] = 15;
		motor[motorTL] = 15;
	}
}

void gripGoal()
{
	//Bring the grips down
	servo[servoHinge1] = 100; //CHANGE VALUES LATER
	servo[servoHinge2] = 0;

	//Grip tightens around the goal
	servo[servoGrip1] = 100; //CHANGE VALUES LATER
	servo[servoGrip2] = 0;
}

void ungripGoal()
{
	//Grip loosens around the goal
	servo[servoGrip1] = 0; //CHANGE VALUES LATER
	servo[servoGrip2] = 100;
}

//task main()
//{
//	goInches(60, 60);
//	turnLeftDegrees(90, 60);

//}

//1440 ticks per revolution
//4 inch diameter wheel
//12.56 inch circumference
//1440 / 12.56 = 114.6 ticks per inch

//1120 / 12.56 = 89.17 ticks per inch
