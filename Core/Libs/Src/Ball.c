#include "Ball.h"

void InitBall(Ball *hball, float *InitPos, float *InitVel){
    hball->posx = InitPos[0];
    hball->posy = InitPos[1];
    hball->velx = InitVel[0];
    hball->vely = InitVel[1];
};


void Update(Ball * hball, float delta_t, float gravity, float frict){
    //Based on specific timer delta_t
    hball -> vely += gravity*delta_t;
    hball -> posx += hball ->velx * delta_t;
    hball -> posy += hball ->vely * delta_t + 0.5*gravity*delta_t*delta_t;

    if (hball -> posx < 0){
        hball -> posx = 0;
        hball -> velx = -hball ->velx*frict;
    } else if (hball -> posx > 0.035){
        hball -> posx = 0.035;
        hball -> velx = -hball ->velx*frict;
    }
    if (hball -> posy < 0){
        hball -> posy = 0;
        hball -> vely = -hball ->vely*frict;
    } else if (hball -> posy > 0.035){
        hball -> posy = 0.035;
        hball -> vely = -hball ->vely*frict;
    }

    hball -> posx_int = (uint8_t)(hball->posx / 0.005);
    
    hball -> posy_int = (uint8_t)(hball->posy / 0.005);
};