#include "include/main.h"

Motor tilter1(TILTER, MOTOR_GEARSET_18, 0, MOTOR_ENCODER_DEGREES);
unsigned int tilterTarget = 0;
int tiltSpeed = 127;

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


/**************************************************/
//task control
void tilterTask(void* parameter){
  int prevError = 0;

  while(1){
    delay(20);

    int sp = tilterTarget;

    double kp = 3.5;
    double kd = 3.0;

    //read sensors
    int sv = tilter1.get_position();

    //speed
    int error = sp-sv;
    int derivative = error - prevError;
    prevError = error;
    int speed = error*kp + derivative*kd;
    //printf("%f @ %d\n", tilter1.get_position(), speed);

    if(speed > tiltSpeed)
      speed = tiltSpeed;
    if(speed < -tiltSpeed)
      speed = -tiltSpeed;

    //set motors
    tilter(speed);
  }
}

int tilterPos()
{
  return tilter1.get_position();
}

void tilterOp(){
  //printf("%f\n", tilter1.get_position());
  tilter1.set_brake_mode(tiltMode);
  //starts 0, ends 1920
  if(master.get_digital(DIGITAL_X))
    {
      if(tilter1.get_position() < (1920/2))
        tilter(127);
      else
        tilterTarget = 1920;
    }
    //tiltTarget = tiltTarget+7;
  else if(master.get_digital(DIGITAL_B))
    tilter(-127);
    //tiltTarget = tiltTarget-7;
    else
    tilter(0);
  /*if(master.get_digital(DIGITAL_B))
  {
    tiltMode = MOTOR_BRAKE_COAST;
    //tilt1.set_brake_mode(tiltMode);
    //tilt2.set_brake_mode(tiltMode);
  }
  else
  {
    tiltMode = MOTOR_BRAKE_HOLD;
    //tilt1.set_brake_mode(tiltMode);
    //tilt2.set_brake_mode(tiltMode);
  }*/
}
