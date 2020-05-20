#include "Sight.h"

Sight::Sight()
{
}

float Sight::distance(int sensor)
{
	return 187754 * pow(sensor, -1.51);
}

int Sight::closest(float* distances)
{

}
// void Sight::senseOpponent()
// {
// 	distances[0] = analogRead(A0);
// 	distances[1] = analogRead(A1);
// 	distances[2] = analogRead(A2);
// 	distances[3] = analogRead(A3);
// 	distances[4] = analogRead(A4);
// 	distances[5] = analogRead(A5);
// 	distances[6] = analogRead(A6);
// 	distances[7] = analogRead(A7);

// }

int Sight::findOpponent()
{	
	int direction[8]={0,45,90,135,180,225,270,315};
	senseOpponent();

	

	uint16_t min = 1000;
	int loc=0;
	for(int i = 0; i <=7 ; i++)
	{
		if(min > calculateDistance(i)) {
			min = calculateDistance(i);
			loc = i;
		}
	}
		
	return loc;
}

// uint16_t Sight::calculateDistance(int ir)
// {
// 	 return 187754 * pow(distances[ir], -1.51);
// }