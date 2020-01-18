#ifndef _LIFT_H_
#define _LIFT_H_

void initTilterBrake();

void tilter(int vel);

void tilterReset();

void asyncTilterTo(int tiltPoint, int speed);

void tilterTask(void* parameter);

int tilterPos();

void tilterOp();

#endif
