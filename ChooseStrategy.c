#include "NXTFileIODefs.h"

//int IntArray[i++] = {"RampAutonomous v1.1.c" , "parkingzoneAutonomous v1.c" , "autoDefense v1"}

void ChooseStrategy()
{
	eraseDisplay(); //Erase the display

	nxtDisplayTextLine(1, "Choose Color: ");
	nxtDisplayStringAt(15, 46, "Red");
	wait1Msec(300); //prevents accidental selections

	while (nNxtButtonPressed != mid)
	{
		if(nNxtButtonPressed == left || nNxtButtonPressed == right)
		{
			if (Color == Blue)
			{
				Color = Red;
				nxtDisplayClearTextLine(2);
				nxtDisplayStringAt(15, 46, "Red");
			}
			else if (Color == Red)
			{
				Color = Blue;
				nxtDisplayClearTextLine(2);
				nxtDisplayStringAt(15, 46, "Blue");
			}
		}
		wait1Msec(300);
	}

	nxtDisplayTextLine(1, "Choose Side:");
	nxtDisplayBigStringAt(15,46, "Left");
	wait1Msec(300);

	while(nNxtButtonPressed != mid)
	{
		if (nNxtButtonPressed == left || nNxtButtonPressed == right)
		{
			if (Side == Left)
			{
				Side = Right;
				nxtDisplayClearTextLine(2);
				nxtDisplayStringAt(15,46, "Right");
			}
			else if(Side == Right)
			{
				Side = Left;
				nxtDisplayClearTextLine(2);
				nxtDisplayStringAt(15,46, "Left");
			}
		}
		wait1Msec(300);
	}
}
