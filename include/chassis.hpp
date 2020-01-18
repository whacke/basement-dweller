#ifndef _CHASSIS_H_
#define _CHASSIS_H_

void reset();

int drivePos();

bool isDriving();

void driveTask(void* parameter);
void turnTask(void* parameter);
void curveTask(void* parameter);


void left(int vel);
void right(int vel);

void driveAsync(int sp, int modifier);
void turnAsync(int sp, int modifier);
void curveAsync(int driving, int turning, int modifier);
void drive(int sp, int mod);
void turn(int sp, int mod);
void curve(int d, int t, int m);
void slowDrive(int sp, int dp);
void basicDrive(int distance, int speed);


void chassisSpeed(int vel);
void setSlant(int s);
void setSpeed(int speed);
void setCurrent(int mA);
void setBrakeMode(int mode);
void driveOp();

#endif
