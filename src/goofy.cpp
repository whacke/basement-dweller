#include "main.h"

Motor goofy1(GOOFY, MOTOR_GEARSET_36, 1, MOTOR_ENCODER_DEGREES);
unsigned int liftTarget = 5;
int liftSpeed = 127;

motor_brake_mode_e_t liftMode = MOTOR_BRAKE_HOLD;

void initGoofyBrake()
{
    goofy1.set_brake_mode(liftMode);
}

void goofy(int lift){
  goofy1.move(lift);
}

void goofyReset()
{
  goofy1.tare_position();
}

void goofyTo(int liftPoint, int speed){
  goofy1.move_absolute(liftPoint, speed);
  while((goofy1.get_position() > liftPoint + 5) || (goofy1.get_position() < liftPoint - 5)) delay(20);
}

void goofyPIDTo(int liftpoint)
{
  liftTarget = liftpoint;
}


/**************************************************/
//task control
void goofyTask(void* parameter){
  int prevError = 0;
  int integral = 0;
  bool activePID = true;
  while(1){
    /*
    delay(20);

    int sp = liftTarget;

    double kp = 20.0;
    double kd = 50.0;
    double kI = 50.0;

    //read sensors
    int sv = goofy1.get_position();

    //speed
    int error = sp-sv;
    integral = integral + error;
    if(error == 0 || error > sv)
      integral = 0;
    if(error > 1000)
      integral = 0;
    int derivative = error - prevError;
    prevError = error;
    int speed = (error*kp) + (integral*kI) + (derivative*kd);
    printf("%f @ %d\n", goofy1.get_position(), speed);

    if(speed > liftSpeed)
      speed = liftSpeed;
    if(speed < -liftSpeed)
      speed = -liftSpeed;

    //set motors
    goofy(speed); */
    if(master.get_digital(DIGITAL_R1))
      {
      goofy(127);
      //liftTarget = liftTarget+10;
      //activePID = false;
      }
      else if(master.get_digital(DIGITAL_R2))
      {
      goofy(-127);
      //liftTarget = liftTarget-10;
      //activePID = false;
      }
      else if(goofy1.get_position() > 1.5 && goofy1.get_position() < 150)
      {
      goofy(-127);
      //activePID = true;
      //liftTarget = 0;
      }
      else if((master.get_digital(DIGITAL_X)))
      {
        goofy(-30);
      }
      else
      {
        goofy(0);
      }
  }
  }

void goofyOp(){
  if(master.get_digital(DIGITAL_R1))
    {
    goofy(127);
    //liftTarget = liftTarget+10;
    //activePID = false;
    }
    else if(master.get_digital(DIGITAL_R2))
    {
    goofy(-127);
    //liftTarget = liftTarget-10;
    //activePID = false;
    }
    else if(goofy1.get_position() > 1.5 && goofy1.get_position() < 200)
    {
    goofy(-127);
    //activePID = true;
    //liftTarget = 0;
    }
    else
    {
      goofy(0);
    }
    printf("%f\n", goofy1.get_position());
}
