#include<SDL.h>
#include"defs.h"
#include"Obstacle.h"
#include"Graphics.h"
void Obstacle::render(Graphics &graphics,Obstacle obstacle,SDL_Texture*Obstacleimage){
    SDL_Rect Top={obstacle.x,0,140,obstacle.height};
    SDL_Rect Bottom={obstacle.x,obstacle.height+OBSTACLE_GAP,140,SCREEN_HEIGHT-OBSTACLE_GAP-obstacle.height};
    SDL_RenderCopy(graphics.renderer,Obstacleimage,NULL,&Top);
    SDL_RenderCopyEx(graphics.renderer,Obstacleimage,NULL,&Bottom,0,NULL,SDL_FLIP_VERTICAL);
}
