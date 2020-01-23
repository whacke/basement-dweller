#ifndef _CHASSIS_H_
#define _CHASSIS_H_

void reset();

int leftPos();
int rightPos();
int drivePos();

bool isDriving();

void driveTask(void* parameter);
void turnTask(void* parameter);
void curveTask(void* parameter);


void left(int vel);
void right(int vel);

void driveAsync(int sp, double modifier);
void turnAsync(int sp, double modifier);
void curveAsync(int driving, int turning, double modifier);
void drive(int sp, double mod);
void turn(int sp, double mod);
void curve(int d, int t, double m);
void slowDrive(int sp, int dp, double mod);
void basicDrive(int distance, int speed);
void leftSwing(int angle, int speed);
void rightSwing(int angle, int speed);


void chassisSpeed(int vel);
void setSlant(int s);
void setSpeed(int speed);
void setCurrent(int mA);
void setBrakeMode(int mode);
void driveOp();

#endif
