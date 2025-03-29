#include<iostream>
#include<string>
#include<SDL.h>
#include<vector>
#include<SDL_mixer.h>
#include<cstdlib>
#include<SDL_image.h>
#include"defs.h"
#include"Obstacle.h"
#include"run.h"
#include"Graphics.h"
#include"buttom.h"
#include"Textureandmusic.h"
using namespace std;
int main(int argc,char*argv[])
{
    rungaming game;
    game.initeverything();
    game.rungame();
    game.quitgame();
    return 0;
}
