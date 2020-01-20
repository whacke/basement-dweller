#include "main.h"

Motor intake1(LEFTINTAKE, MOTOR_GEARSET_36, 0, MOTOR_ENCODER_DEGREES);
Motor intake2(RIGHTINTAKE, MOTOR_GEARSET_36, 1, MOTOR_ENCODER_DEGREES);

ADILineSensor intakeSense('B');

void initIntakeBrake(){
  motor_brake_mode_e_t brakeMode = MOTOR_BRAKE_HOLD;
  intake1.set_brake_mode(brakeMode);
  intake2.set_brake_mode(brakeMode);
}

void intake(int intake){
  intake1.move(intake);
  intake2.move(intake);
}

void cubeLower()
{
  if(intakeSense.get_value() > 2800)
    printf("THE CONDITION SHOULD BE TRUE\n");
  while(intakeSense.get_value() > 2800)
  {
    intake(-63);
    delay(20);
    printf("%d\n", intakeSense.get_value());
  }
  intake(20);
}

bool idleIntake = false;
void intakeOp(){
  printf("%d\n", intakeSense.get_value());
  if(master.get_digital(DIGITAL_L2))
    intake(127);
  else if(master.get_digital(DIGITAL_L1))
    intake(-42);
  else if(master.get_digital(DIGITAL_UP))
    intake(-127);
  else if(master.get_digital(DIGITAL_Y))
    intake(-30);
  else{
      if(idleIntake == true)
      intake(20);
      else
      intake(0);
  }
  if(master.get_digital_new_press(DIGITAL_A))
  {
    if(idleIntake == true)
      idleIntake = false;
    else
      idleIntake = true;
  }
  if(tilterPos() > (1920/2))
    idleIntake = false;
}
