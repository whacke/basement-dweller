#include "main.h"

void dump()
{
  intake(0);
  goofy(-15);
  while(tilterPos() < 1650)
  {

    tilterTune(0.11);
    if(tilterPos() < (1920-(1920/3)) && tilterPos() > (1920/2))
    {

      intake(-35); //was -20
      chassisSpeed(0);
      delay(10);
    }
  }
  if(auton == 5) delay(500);
  intake(-60); //was -50
  asyncTilterTo(0);
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
    cubeLower();
    intake(20);
    while(true)
    {
    if(cubePresent() == true)
    printf("True!\n");
    else
    printf("False!\n");
    }


    break;

    case 1:
    foldOut();
    delay(250);
    drive((2.37+0.73) TL, 1.9);
    //basicDrive(0.25 TL, 30); goofy(0); basicDrive(1.7 TL, 50);
    goofy(0);
    while(cubePresent()) delay(20);
    basicDrive(-0.55 TL, 50);
    drive((-1-0.73) TL, 1);
    turn(-152, 2);
    delay(250);
    cubeLower();
    intake(20);
    //drive(1.32 TL, 1.75);
    basicDrive(1, 60);
    chassisSpeed(60);
    delay(500);
    chassisSpeed(35);
    delay(750);
    asyncTilterTo(1650);
    dump();

    break;

    case 2:
    foldOut();
    delay(500);
    drive((2.37+0.73) TL, 1.9);
    //basicDrive(0.25 TL, 30); goofy(0); basicDrive(1.7 TL, 50);
    goofy(0);
    delay(250);
    basicDrive(-0.55 TL, 50);
    drive((-1-0.73) TL, 1);
    turn(155, 2);
    delay(250);
    cubeLower();
    intake(20);
    //drive(1.3 TL, 1.75);
    basicDrive(1, 60);
    chassisSpeed(60);
    delay(500);
    chassisSpeed(35);
    delay(750);
    asyncTilterTo(1650);
    dump();

    break;

    case 3:

    foldOut();
    drive(1.8 TL, 1.5);
    goofy(0);
    while(cubePresent()) delay(20);
    turn(40, 0.8);
    drive(-1.9 TL, 1);
    turn(-47, 0.8);
    drive(2.2 TL, 1.7);
    while(cubePresent()) delay(20);
    //basicDrive(-0.55 TL, 50);
    cubeLower();
    asyncTilterTo(910);
    drive(-1.25 TL, 0.8); //was 1 and 1
    turn(-148, 1.5);
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

    case 5:

    //turn(int sp, double mod);
    //drive(int sp, double mod);
    //basicDrive(int distance, int speed);
    //intake(int vel);
    //goofyTo(int liftPoint, int speed);
    //asyncGoofyTo(int liftPoint, int speed);
    //asyncTilterTo(int tiltPoint);
    //cubeLower();
    //cubePresent();
    //while(cubePresent()) delay(20);

    foldOut();
    delay(500);
    basicDrive(0.075 TL, 65);
    delay(250);
    turn(-57, 1);
    cubeLower();
    intake(0);
    goofyTo(225, 60);
    basicDrive(0.76 TL, 50);
    intake(-44);
    delay(750);
    //drive back from first tower
    basicDrive(0.8 TL, -50);
    intake(0);
    delay(250);
    turn(53, 1);
    basicDrive(1, -60);
    chassisSpeed(-60);
    asyncGoofyTo(0, -60);
    delay(1500);
    chassisSpeed(0);
    //end wall press
    intake(127);
    goofy(-20);
    drive(2 TL, 1.5);
    while(cubePresent()) delay(20);
    delay(500);
    turn(-50, 1);
    basicDrive(0.3 TL, 60);
    delay(250);
    turn(63, 1);
    basicDrive(0.5 TL, 40);
    while(cubePresent()) delay(20);
    delay(200);
  //basicDrive(0.20 TL, -20);
    turn(-25, 1);
    drive(3.1 TL, 2);
    turn(-20, 1);
    basicDrive(1, -60);
    chassisSpeed(40);
    delay(2500);
    chassisSpeed(0);
    basicDrive(0.5 TL, -60);
    delay(200);
    turn(-56, 1); //stack turn
    reset();
    basicDrive(1, 50);
    cubeLower();
    intake(20);
    chassisSpeed(50);
    delay(1000);

    //chassisSpeed(40);
    asyncTilterTo(1700);
    dump();
    intake(127);
    delay(250);
    turn(57, 1); //turn for wall press
    basicDrive(1, 40);
    chassisSpeed(40);
    delay(2500);
    chassisSpeed(0);
    basicDrive(0.3 TL, -50);
    delay(200);
    turn(94, 1);
    delay(250);
    drive(1 TL, 50);
    chassisSpeed(40);
    delay(2500);
    chassisSpeed(0);
    drive(0.3 TL, -50);
    goofyTo(300, 60);
    intake(-44);





    break;

  }
}


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

/* U Route
drive(2.42 TL, 1.8);
goofy(0);
while(cubePresent()) delay(20);
curve(0.2 TL, 90, 1.75);
curve(0.25 TL, 50, 1.75);
goofy(-15);
delay(150);
*/
