#include "Move.h"

Move::Move()
{
}
void Move::forward()
{
	fl_motor.direction('b');
	fr_motor.direction('b');
	//br_motor.direction('f');
	//bl_motor.direction('f');
	//for(int i = 150; i < value; i++){
	fl_motor.power(value);
	fr_motor.power(value);
	//br_motor.power(i);
	//bl_motor.power(i);
	//}
}
void Move::backward()
{
	fl_motor.direction('f');
	fr_motor.direction('f');
	//br_motor.direction('b');
	//bl_motor.direction('b');

	fl_motor.power(value);
	fr_motor.power(value);
	//br_motor.power(value);
	//bl_motor.power(value);
}

void Move::left()
{
	fl_motor.direction('b');
	//br_motor.direction('f');
	fr_motor.direction('f');
	//bl_motor.direction('b');

	fl_motor.power(0);
	fr_motor.power(value);
	//br_motor.power(value);
	//bl_motor.power(0);
}

void Move::right()
{
	fl_motor.direction('f');
	fr_motor.direction('b');
	//br_motor.direction('b');
	//bl_motor.direction('f');

	fl_motor.power(value);
	fr_motor.power(0);
	//br_motor.power(value);
	//bl_motor.power(value);
}

void Move::stop()
{
	fr_motor.power(0);
	fl_motor.power(0);
	//br_motor.power(value);
	//bl_motor.power(value);
}

long Move::read()
{
	// Serial.print(fl_encoder.read());
	// Serial.print(fr_encoder.read());
	// Serial.print(br_encoder.read());
	Serial.print(bl_encoder.read());
	Serial.println();
}

/*
void Move::forwardenc()
{
	Serial.println("Fenc");
	updateForward();
	fl_encoder.write(Lnextposition);
	fr_encoder.write(Lnextposition);
	br_encoder.write(Rnextposition);
	bl_encoder.write(Rnextposition);

}
void Move::backwardenc()
{
	Serial.println("Benc");
	updateBackward();
	fl_encoder.write(Lnextposition);
	fr_encoder.write(Lnextposition);
	br_encoder.write(Rnextposition);
	bl_encoder.write(Rnextposition);

}
void Move::rightenc()
{
	Serial.println("Renc");
	updateRight();
	fl_encoder.write(Lnextposition);
	fr_encoder.write(Lnextposition);
	br_encoder.write(Rnextposition);
	bl_encoder.write(Rnextposition);

}
void Move::leftenc()
{
	Serial.println("Renc");
	updateLeft();
	fl_encoder.write(Lnextposition);
	fr_encoder.write(Lnextposition);
	br_encoder.write(Rnextposition);
	bl_encoder.write(Rnextposition);

}
void Move::stopenc()
{
	Serial.println("Renc");
	updateStop();
	fl_encoder.write(Lnextposition);
	fr_encoder.write(Lnextposition);
	br_encoder.write(Rnextposition);
	bl_encoder.write(Rnextposition);

}
void Move::updateForward()
{
	Serial.println("Updating Encoder Position Forward");
	Rcurrentposition = fr_encoder.read();
	Lcurrentposition = fl_encoder.read();

	// For the difference between current and expected position (next)
	// if current is less than next => reduce next
	if(Rcurrentposition < Rnextposition)
	{
		Rnextposition--;
		Lnextposition--;
	}
	// if current is great than or equal to previous => increase next
	if(Rcurrentposition >= Rnextposition)
	{
		Rnextposition++;
		Lnextposition++;
	}
}
void Move::updateBackward()
{
	Serial.println("Updating Encoder Position Backward");
	Rcurrentposition = fr_encoder.read();
	Lcurrentposition = fl_encoder.read();

	// For the difference between current and expected position (next)
	// if current is less than next => reduce next
	if(Rcurrentposition <= Rnextposition)
	{
		Rnextposition--;
		Lnextposition--;
	}
	// if current is great than or equal to previous => increase next
	if(Rcurrentposition > Rnextposition)
	{
		Rnextposition++;
		Lnextposition++;
	}
}
void Move::updateRight()
{
	Serial.println("Updating Encoder Position Backward");
	Rcurrentposition = fr_encoder.read();
	Lcurrentposition = fl_encoder.read();

	// For the difference between current and expected position (next)
	// if current is less than next => reduce next
	if(Rcurrentposition <= Rnextposition)
	{
		Rnextposition--;
		Lnextposition++;
	}
	// if current is great than or equal to previous => increase next
	if(Rcurrentposition > Rnextposition)
	{
		Rnextposition++;
		Lnextposition--;
	}
}
void Move::updateLeft()
{
	Serial.println("Updating Encoder Position Backward");
	Rcurrentposition = fr_encoder.read();
	Lcurrentposition = fl_encoder.read();

	// For the difference between current and expected position (next)
	// if current is less than next => reduce next
	if(Lcurrentposition <= Lnextposition)
	{
		Rnextposition++;
		Lnextposition--;
	}
	// if current is great than or equal to previous => increase next
	if(Lcurrentposition > Lnextposition)
	{
		Rnextposition--;
		Lnextposition++;
	}
}
void Move::updateStop()
{
	Serial.println("Stopping Encoders");
	Rcurrentposition = fr_encoder.read();
	Lcurrentposition = fl_encoder.read();
	Rnextposition = Rcurrentposition;
	Lnextposition = Lcurrentposition;
}*/