#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S2,     LightSensor,    sensorLightActive)
#pragma config(Motor,  mtr_S1_C2_1,     rightDrive,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     leftDrive,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_2,     intake,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    leftTalon,            tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    rightTalon,           tServoStandard)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

float motorScale (int c)
{
	int d;
	d = (float)(100*c)/128;
	return d;
}

void motorDrive (int x, int y)
	{

		x = motorScale(x);
		y = motorScale(y);
		motor[leftDrive]	= y + x;
		motor[rightDrive]	= y - x;
	}

task main()
{
	while (true)
	{
		if(SensorValue(LightSensor) > 50)
		{

			motor[leftDrive] = -25;
			motor[rightDrive] = 0;

		}

		else if(SensorValue(LightSensor) <= 50)
		{
			motor[leftDrive] = 0;
			motor[rightDrive] = -25;
		}
	}
}
