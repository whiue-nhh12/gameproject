#ifndef _Obstacle_h
#define _Obstacle_h
#include"Graphics.h"
struct Obstacle{
    int x;
    int height;
    bool passed=false;
    void render(Graphics &graphics,Obstacle obstacle,SDL_Texture*Obstacleimage);
};
#endif
