#ifndef _GOOFY_H_
#define _GOOFY_H_

void initGoofyBrake();

void goofy(int vel);

void goofyReset();

void asyncGoofyTo(int liftPoint, int speed);

void goofyTo(int liftPoint, int speed);

void goofyPIDTo(int liftpoint);

void liftCoast();

void goofyTask(void* parameter);

void goofyOp();

#endif
