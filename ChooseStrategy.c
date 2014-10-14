#include "NXTFileIODefs.h"

//int IntArray[i++] = {"RampAutonomous v1.1.c" , "parkingzoneAutonomous v1.c" , "autoDefense v1"}

void ChooseStrategy()
{
	eraseDisplay(); //Erase the display
	wait1Msec(300); //prevents accidental selections
	nxtDisplayTextLine(1, "Choose Color: ");
	nxtDisplayStringAt(15, 46, "Red");
	//sets variables for nxt buttons)
	int mid = 3;
	int right = 1;
	int left = 2;
	string Color = "Red";
	while (nNxtButtonPressed != mid)
	{
		if(nNxtButtonPressed == left || nNxtButtonPressed == right)
		{
			if (Color == "Blue")
			{
				Color = "Red";
				nxtDisplayClearTextLine(2);
				nxtDisplayStringAt(15, 46, "Red");
			}
			else if (Color == "Red")
			{
				Color = "Blue";
				nxtDisplayClearTextLine(2);
				nxtDisplayStringAt(15, 46, "Blue");
			}
		}
		wait1Msec(300);
	}
}
