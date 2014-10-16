
/* TASKS TO DO
	1. Go to the other side's Rolling Goals
	2. Move back and forth in front of the Rolling Goals
*/
task main()
{
initializeRobot();

  waitForStart(); // Wait for the beginning of autonomous phase.

	//move forward
	motor[motorTL] = 60;
	motor[motorTR] = 60;
	motor[motorBL] = 60;
	motor[motorBR] = 60;

	//move back and forth
	while(true)
	{
		motor[motorTL] = 60;
		motor[motorTR] = 60;
		motor[motorBL] = 60;
		motor[motorBR] = 60;

		wait1Msec(1000);

		motor[motorTL] = -60;
		motor[motorTR] = -60;
		motor[motorBL] = -60;
		motor[motorBR] = -60;

		wait1Msec(1000);
	}


}
