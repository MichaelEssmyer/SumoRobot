#include <Arduino.h>

#include "Move.h"
//#include "Sight.h"
//#include "LineSensor.h"

Move move = Move();
int sensors[8];
byte pins[4] = {22,23,24,25};
bool black[4];
bool found=false;
//Sight sight = Sight();
//LineSensor lineSensor = LineSensor();

void pause(int times = 1)
{
  delay(250*times);  
}

//VVVVVVVVVVVVVVVVV
int CheckState()
{
  ReadSensors();
  for(int i = 0; i < 4; i++)
    if(black[i] == 0)
      return i+1;
  return 0;
}

void ReadSensors()
{
  for(int i = 0; i < 4; i++)
    ReadOneSensor(i);
}

void ReadOneSensor(int i )
{
  pinMode(pins[i], OUTPUT);
  digitalWrite(pins[i], HIGH);
  delayMicroseconds(10);
  pinMode(pins[i], INPUT);

  long time = micros();

  while(digitalRead(pins[i]) == HIGH && micros() - time < 3000);
  
  int diff = micros()- time;

  if(diff > 2700)
    black[i] = 1;
  else
    black[i] = 0;
  
}
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//SIGHT 
int findOpponent()
{ 
  int direction[2]={0,180};
  uint16_t min = 200;
  int loc=0;
  for(int i = 0; i <=1 ; i++)
  {
    if(min > distance(sensors[i])) {
      min = distance(sensors[i]);
      loc = i;
      found = true;
    }
    else if (min == 200){
      found = false;
      }
  }
    
  return direction[loc];
}

float distance(int sensor)
{
  return 187754 * pow(sensor, -1.51);
}
//MOVEMENT
void attack()
{
  //int closestSensor = sight.closest()
  int direction = findOpponent();
     
  Serial.print(direction);
  Serial.print(':');


  if (direction == 0)
    move.forward();
  else if(direction > 0 and direction <= 90) 
    move.right();
  else if(direction > 90 and direction < 180) 
    move.left();
  else if (direction == 180)
    move.backward();
  else if (direction > 180 and direction <= 270) 
    move.right();
  else if (direction >=270)
    move.left();
  pause();
}

void stateControl()
{ while(found==false)
  { move.forward();
    //pause();
    move.right();
    //pause();
  }
  switch (CheckState())
    {
    case 0:
        attack();
    case 1: //pin 2 45*
      Serial.println("1 : 45");
      move.left();
      //pause(2);
      move.forward();
      //pause();
      break;
    case 2: //pin 3 135*
      Serial.println("2 : 135");
      move.right();
      //pause(2);
      move.backward();
      //pause();
      break;
    case 3: //pin 4 225*
      Serial.println("3 : 225");
      move.left();
      //pause(2);
      move.backward();
      //pause();
      break;
    case 4: //pin 5 315*
      Serial.println("4 : 315");
      move.right();
      //pause(2);
      move.forward();
      //pause();
      break;

    }
}

///////////////////////////////////////
void setup()
{ 
  Serial.begin(9600);
  delay(5000);
}

void loop()
{ 
  //Get info from IR sensors
  int sensors[2] = {
      analogRead(A0),
      analogRead(A4),
    };

  stateControl();
  //move.forward();
//  move.stop();
}
