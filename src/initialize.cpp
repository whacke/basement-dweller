#include "main.h"

int auton = 5; //this is like an array
bool mirror = false;

ADIButton nav('G');
//ADIButton color('C');

void autonSelector(void* parameter){
	delay(200);

	const int autoCount = 6; //this is not like an array
	const char *autoNames[autoCount] = {
		"red 9 cube DONT USE", "red 5 cube", "blue 5 cube", "red 8 cube", "blue 8 cube", "prog skills"
	};

	lcd::initialize();
	lcd::set_text(0, "Select an Auton");
	lcd::print(2, "%s", autoNames[auton]);
	//lcd::print(4, "%s", mirror ? "blue" : "red");

	while(true)
	{
		if(nav.get_value() == true){
			auton++;
			if (auton == autoCount)
				auton = 0;

			lcd::print(2, "%s", autoNames[auton]);
			while(nav.get_value() == true) delay(20);
			delay(300);
		}
		/*
		if(color.get_value() == true){
			mirror = !mirror;
			lcd::print(4, "%s", mirror ? "blue" : "red");
			while(color.get_value() == true) delay(20);
			delay(300);
		}
		*/
		delay(50);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	initIntakeBrake();
	initGoofyBrake();
	initTilterBrake();
	Task lcd_task(autonSelector);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
