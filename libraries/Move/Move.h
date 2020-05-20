#include <Arduino.h>
#include <Encoder.h>
#include "MotorDriver.h"

class Move
{
public:
	//Control power
	int value = 225;
	
	MotorDriver fr_motor = MotorDriver(A3, 9, 1);
	//MotorDriver br_motor = MotorDriver(A9, 27, 1);
	//MotorDriver bl_motor = MotorDriver(A10, 28, 1);
	MotorDriver fl_motor = MotorDriver(A2, 8, 1);

	Encoder fr_encoder = Encoder(18, 30);
	Encoder br_encoder = Encoder(19, 31);
	Encoder bl_encoder = Encoder(20, 32);
	Encoder fl_encoder = Encoder(21, 33);

	Move();

	void forward();
	void backward();
	void left();
	void right();
	void stop();

	void test();
	long read();
	void direction();

};

//tablelength/wheelcircumference*75

//8.42in/ft * 12