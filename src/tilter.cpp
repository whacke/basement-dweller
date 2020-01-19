#include "main.h"

Motor tilter1(TILTER, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES);
unsigned int tilterTarget = 0;
int tiltSpeed = 127;
double tiltKp = 3.5;

motor_brake_mode_e_t tiltMode = MOTOR_BRAKE_HOLD;

void initTilterBrake()
{
    tilter1.set_brake_mode(tiltMode);
}

void tilter(int tilt){
  tilter1.move(tilt);
}

void tilterReset()
{
  tilter1.tare_position();
}

void asyncTilterTo(int tiltPoint){
  tilterTarget = tiltPoint;
}

int tilterPos()
{
  return tilter1.get_position();
}

/**************************************************/
//task control
void tilterTask(void* parameter){
  int prevError = 0;

  while(competition::is_autonomous() == true){
    delay(20);

    int sp = tilterTarget;

    //read sensors
    int sv = tilter1.get_position();

    //speed
    int error = sp-sv;
    prevError = error;
    int speed = error*tiltKp;
    //printf("%f @ %d\n", tilter1.get_position(), speed);

    if(speed > tiltSpeed)
      speed = tiltSpeed;
    if(speed < -tiltSpeed)
      speed = -tiltSpeed;

    //set motors

    if(tilter1.get_position< (1920/2))
      tilter(tiltSpeed);
    else
      tilter(speed);

  }
}


void tilterOp(){
  //printf("%f\n", tilter1.get_position());
  tilter1.set_brake_mode(tiltMode);
  if(master.get_digital(DIGITAL_X))
    {
      if(tilterPos() < (1920/2))
        tilter(100); int prevError = 0;
      else
      {
        int sp = 1650;

        //read sensors
        int sv = tilter1.get_position();

        //speed
        int error = sp-sv;
        prevError = error;
        int speed = error*tiltKp;
        //printf("%f @ %d\n", tilter1.get_position(), speed);

        if(speed > tiltSpeed)
          speed = tiltSpeed;
        tilter(40);
      }
    }
  else if(master.get_digital(DIGITAL_B))
    tilter(-127);
  else
    tilter(0);
}
