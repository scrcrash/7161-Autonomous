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


#include "C:\Users\viperbots\Documents\GitHub\7161-Autonomous\AutonomousChooserHeaders.c"
#include "C:\Users\viperbots\Documents\GitHub\7161-Autonomous\CommonFiles.c"
#include "C:\Users\viperbots\Documents\GitHub\7161-Autonomous\ChooseStrategy.c"

//autonomous files
task main
{
	if(Side == ParkingZone)
	{
		if(Color == Red)
		{
			if(Strategy == Offense)
			{
				stopAllTasks();
			}
		}
	}
}
