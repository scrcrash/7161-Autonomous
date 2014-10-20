/* TASKS TO DO
	1. Go to the Center Goal
	2. Find the IR Beacon
	3. Score ball
	4. Go to Kickstand
	5. Hit Kickstand
*/

task main()
{
	//reset encoders
	nMotorEncoder[motorTR] = 0;
	nMotorEncoder[motorTL] = 0;
	nMotorEncoder[motorBR] = 0;
	nMotorEncoder[motorBL] = 0;

	while(nMotorEncoder[motorTR] < 2300)
	{
		motor[motorTR] = 20;
		motor[motorTL] = 20;
		motor[motorBR] = 20;
		motor[motorBL] = 20;
	}
}
