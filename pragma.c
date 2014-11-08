#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Hubs,  S2, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     IRSensor,       sensorHiTechnicIRSeeker600)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_1,     motorBR,       tmotorTetrix, openLoop, reversed, driveRight)
#pragma config(Motor,  mtr_S1_C1_2,     motorBL,       tmotorTetrix, openLoop, driveLeft)
#pragma config(Motor,  mtr_S1_C2_1,     motorTR,       tmotorTetrix, PIDControl, reversed, driveRight, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorTL,       tmotorTetrix, PIDControl, driveLeft, encoder)
#pragma config(Motor,  mtr_S1_C3_1,     motorPulley,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorb,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_1,     motora,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C1_2,     motorBrush,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servoHingeL,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_2,    servoGripL,           tServoStandard)
#pragma config(Servo,  srvo_S1_C4_3,    servoHingeR,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    servoGripR,           tServoStandard)
#pragma config(Servo,  srvo_S1_C4_5,    servoBasket,          tServoStandard)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "CommonFiles.c"
//#include "AutonomousChooserHeaders.c"
//#include "AutonomousChooserProgram.c"
//#include "ChooseStrategy.c"
