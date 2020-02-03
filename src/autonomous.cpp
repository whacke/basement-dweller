#include "main.h"

void dump()
{
  intake(0);
  goofy(-15);
  while(tilterPos() < 1650)
  {
    tilterTune(0.1);
    if(tilterPos() < (1920-(1920/3)) && tilterPos() > (1920/2))
    {

      intake(-35); //was -20
      chassisSpeed(0);
      delay(10);
    }
  }
  intake(-35); //was -50
  asyncTilterTo(0);
  if(auton == 0)
    basicDrive(1 TL, -70);
  else
    basicDrive(0.6 TL, -50);
  goofy(0);
}


void foldOut()
{
  chassisSpeed(-20);
  intake(-127);
  delay(500);
  goofyTo(50, 127);
  delay(250);
  goofyTo(0, -127);
  intake(127);
  goofy(-15);
  delay(150);

}


void autonomous() {
  Task drive_task(driveTask);
  Task turn_task(turnTask);
  Task curve_task(curveTask);
  Task tilter_task(tilterTask);



  switch (auton){

    case 0:
    foldOut();
    drive(2.37 TL, 1.8);
    goofy(0);
    while(cubePresent()) delay(20);
    curve(0.2 TL, 90, 1.75);
    curve(0.25 TL, 70, 1.75);
    goofy(-15);
    curve(0.25 TL, 35, 1.25);
    curve(-0.5 TL, 35, 1.25);
    //curve(0.5 TL, 180, 8);
    delay(150);
    drive(0.6 TL, 1);
    rightSwing(650, 80); //was 750
    /*
    curve(0.2 TL, 90, 1.75);
    curve(0.25 TL, 70, 2.25);
    turn(82, 2);
    */
    cubeLower();
    asyncTilterTo(710);
    basicDrive(0.5 TL, 40);
    basicDrive(1.5 TL, 70);
    asyncTilterTo(1650);
    chassisSpeed(40);
    dump();

    break;

    case 1:
    foldOut();
    drive(2.37 TL, 1.9);
    //basicDrive(0.25 TL, 30); goofy(0); basicDrive(1.7 TL, 50);
    goofy(0);
    while(cubePresent()) delay(20);
    basicDrive(-0.55 TL, 50);
    drive(-1 TL, 1);
    turn(-152, 2);
    delay(250);
    cubeLower();
    intake(20);
    //drive(1.32 TL, 1.75);
    basicDrive(0.5 TL, 45);
    chassisSpeed(50);
    delay(750);
    asyncTilterTo(1650);
    dump();

    break;

    case 2:
    foldOut();
    delay(500);
    drive(2.37 TL, 1.9);
    //basicDrive(0.25 TL, 30); goofy(0); basicDrive(1.7 TL, 50);
    goofy(0);
    delay(250);
    basicDrive(-0.55 TL, 50);
    drive(-1 TL, 1);
    turn(155, 2);
    delay(250);
    cubeLower();
    //drive(1.3 TL, 1.75);
    basicDrive(0.5 TL, 45);
    chassisSpeed(50);
    delay(750);
    asyncTilterTo(1650);
    dump();

    break;

    case 3:

    foldOut();
    drive(1.8 TL, 1.5);
    goofy(0);
    while(cubePresent()) delay(20);
    turn(40, 0.9);
    drive(-1.8 TL, 0.7);
    turn(-47, 0.9);
    drive(2.2 TL, 1.7);
    while(cubePresent()) delay(20);
    //basicDrive(-0.55 TL, 50);
    cubeLower();
    asyncTilterTo(910);
    drive(-1.25 TL, 0.8); //was 1 and 1
    turn(-144, 1.5);
    //drive(1.5 TL, 0.8);
    basicDrive(1 TL, 60);
    chassisSpeed(50);
    delay(250);
    //chassisSpeed(40);
    asyncTilterTo(1650);
    dump();

    break;

    case 4:

    foldOut();
    drive(1.8 TL, 1.5);
    goofy(0);
    while(cubePresent()) delay(20);
    turn(-40, 1);
    drive(-1.8 TL, 1);
    turn(47, 1);
    drive(2.2 TL, 1.7);
    while(cubePresent()) delay(20);
    //basicDrive(-0.55 TL, 50);
    cubeLower();
    asyncTilterTo(910);
    drive(-1.25 TL, 0.8); //was 1 and 1
    turn(148, 1.5);
    basicDrive(1 TL, 60);
    chassisSpeed(50);
    delay(250);

    //chassisSpeed(40);
    asyncTilterTo(1650);
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
