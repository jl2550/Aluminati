#pragma config(Hubs,  S2, HTServo,  HTMotor,  HTMotor,  none)
#pragma config(Sensor, S1,     sensorLight,    sensorLightActive)
#pragma config(Motor,  mtr_S2_C2_1,     motorIntake,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C2_2,     motorArm,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C3_1,     motorBLeftWs,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S2_C3_2,     motorBRightWs,  tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S2_C1_1,    servoHook,            tServoStandard)
#pragma config(Servo,  srvo_S2_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S2_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	motor[motorBRightWs] = 75;
	motor[motorBLeftWs] = 75;
	wait1Msec(1000);
	motor[motorBRightWs] = 60;
	motor[motorBLeftWs] = 75;
	black = 11;
	white = 99;`
	loops = 0
	midpoint = ( white + black ) / 2;
	while (loops < 10000000)
	{
		value = SensorValue(sensorLight);
		if value > midpoint
		{
			motor[motorBRightWs] = 75;
			motor[motorBLeftWs] = 60;
		}
		else if value < midpoint
		{
			motor[motorBLeftWs] = 75;
			motor[motorBRightWs] = 60;
		}
		loops++;
	}

}
