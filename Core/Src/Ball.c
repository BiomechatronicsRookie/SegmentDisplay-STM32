#include "Ball.h"

void InitBall(Ball *hball, float *InitPos, float *InitVel){
    hball->posx = InitPos[0];
    hball->posy = InitPos[1];
    hball->velx = InitVel[0];
    hball->vely = InitVel[0];
};


void Update(Ball * hball, float delta_t){
    //Based on specific timer delta_t
    hball -> posx += hball ->velx * delta_t;
    hball -> posy += hball ->vely * delta_t;

    if (hball -> posx < 0){
        hball -> posx = 0;
        hball -> velx = -hball ->velx*0.9;
    } else if (hball -> posx > 8){
        hball -> posx = 8;
        hball -> velx = -hball ->velx*0.9;
    }
    if (hball -> posy < 0){
        hball -> posy = 0;
        hball -> vely = -hball ->vely*0.9;
    } else if (hball -> posx > 8){
        hball -> posy = 8;
        hball -> vely = -hball ->vely*0.9;
    }

    hball -> posx_int = (int)hball->posx;
    hball -> posy_int = (int)hball->posy;
};