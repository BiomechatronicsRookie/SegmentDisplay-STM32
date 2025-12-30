#ifndef _BALL_H
#define _BALL_H

#include <stdint.h>
#endif

typedef struct{
uint8_t posx_int;
uint8_t posy_int;
float posx;
float posy;
float velx;
float vely;
} Ball;

void Update(Ball * hball, float deltat_t);

void InitBall(Ball * hball, float * InitPos, float * InitVel);
