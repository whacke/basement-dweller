#include "main.h"
Controller master(CONTROLLER_MASTER);
void opcontrol() {
	initGoofyBrake();
	initIntakeBrake();
Task goofy_task(goofyTask);
	while (true) {

		driveOp();
		tilterOp();
		//goofyOp();
		intakeOp();

		delay(10);
	}
}
