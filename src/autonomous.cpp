#include "main.h"

void dump()
{
  intake(0);
  while(tilterPos() < 1650)
  {
    if(tilterPos() < (1920/2))
      tilter(127);
    else if(tilterPos() < (1920-(1920/3)) && tilterPos() > (1920/2))
    {
      tilter(63);
      intake(-20);
      chassisSpeed(0);
    }
    else
      tilter(40);
  }
  tilter(0);
  intake(-40);
  delay(250);
  intake(-50); //was -30
  basicDrive(1 TL, -30);
}


void autonomous() {
  Task drive_task(driveTask);
  Task turn_task(turnTask);
  Task curve_task(curveTask);



  switch(auton){
  case 0:

  chassisSpeed(0);
  intake(-127);
  delay(1000);
  goofy(127);
  delay(500);
  goofy(-127);
  intake(127);
  delay(500);
  basicDrive(0.25 TL, 30); goofy(0); basicDrive(1.7 TL, 50);
  goofy(0);
  delay(250);
  basicDrive(-0.55 TL, 50);
  drive(-1 TL, 1);
  turn(-150, 2);
  delay(250);
  intake(-75);
  delay(300);
  intake(20);
  basicDrive(0.7 TL, 45);
  drive(1.1 TL, 1);
  dump();

  break;

  case 1:

  chassisSpeed(0);
  intake(-127);
  delay(1000);
  goofy(127);
  delay(500);
  goofy(-127);
  intake(127);
  delay(500);
  basicDrive(0.25 TL, 30); goofy(0); basicDrive(1.7 TL, 50);
  goofy(0);
  delay(250);
  basicDrive(-0.55 TL, 50);
  drive(-1 TL, 1);
  turn(155, 2);
  delay(250);
  intake(-75);
  delay(300);
  intake(20);
  basicDrive(0.7 TL, 45);
  drive(1 TL, 1);
  dump();

  break;

  }

  }


/* MY 6 CUBE
intake(127);
basicDrive(0.25 TL, 30); basicDrive(1.4 TL, 50);
delay(500);
turn(35, 1);
delay(250);
basicDrive(0.3 TL, 30);
delay(150);
basicDrive(-0.25 TL, 30);
turn(-35, 1);
basicDrive(-0.25 TL, 50);
drive(-1 TL, 1);
turn(-135, 1);
delay(250);
basicDrive(0.7 TL, 45);
drive(0.7 TL, 1);
dump();
basicDrive(-1 TL, 45);
intake(-45);
*/

/* MY 7 CUBE
intake(127);
basicDrive(0.1 TL, 40);
basicDrive(1.05 TL, 50);
basicDrive(0.5 TL, 30);
delay(150);
turn(35, 1);
//delay(150);
basicDrive(0.3 TL, 40);
delay(150);
basicDrive(-0.25 TL, 40);
turn(-35, 1);
//delay(100);
basicDrive(0.5 TL, 60);
delay(250);
basicDrive(-0.25 TL, 40);
intake(20);
basicDrive(-0.9 TL, 80);
basicDrive(-0.25 TL, 40);
delay(250);
turn(-150, 2);

//basicDrive(0.5 TL, 40);
//chassisSpeed(30);
//dump();
*/

/* MY 8 CUBE
delay(500); //fake foldout
//start
Task goofy_task(goofyTask);
intake(127);
basicDrive(0.55 TL, 70);
basicDrive(1 TL, 50);
delay(150);
//curve(-0.5 TL, 900, 6);
turn(40, 1);
basicDrive(0.25 TL, -50);
basicDrive(1.5 TL, -100); //were -40 and 80
basicDrive(0.25 TL, -50);
delay(250);
turn(-39, 1);
//curve(-2 TL, 85, 15);
//delay(150);
basicDrive(0.55 TL, 60);
basicDrive(1.35 TL, 50);
//basicDrive(0.25 TL, 40);
delay(500);
turn(-163, 2);
intake(20);
delay(150);
basicDrive(0.25 TL, 40);
basicDrive(1.1 TL, 80);
tilter(127);
basicDrive(0.25 TL, 40);
intake(0);
chassisSpeed(30);
dump();
*/
