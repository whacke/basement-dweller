#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS


#include "api.h"
#include "chassis.hpp"
#include "intake.hpp"
#include "tilter.hpp"
#include "goofy.hpp"
//ports
#define LEFTFRONT 2
#define LEFTBACK 3
#define RIGHTFRONT 6
#define RIGHTBACK 20
#define GOOFY 10
#define TILTER 4
#define LEFTINTAKE 15
#define RIGHTINTAKE 17
//definition of a tile in encoder ticks
#define TL *545
//definition of a cube height in encoder ticks
#define OBJ *120

using namespace pros;
using namespace pros::literals;

extern Controller master;
extern bool mirror;
extern int auton;

#ifdef __cplusplus
extern "C" {
#endif
void autonomous(void);
void initialize(void);
void disabled(void);
void competition_initialize(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */
//#include <iostream>
#endif

#endif  // _PROS_MAIN_H_
