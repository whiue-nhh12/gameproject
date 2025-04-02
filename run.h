#ifndef _rungaming_h
#define _rungaming_h
#include<string>
#include<vector>
#include<SDL.h>
#include<vector>
#include<SDL_mixer.h>
#include<SDL_image.h>
#include"defs.h"
#include"Graphics.h"
#include"Obstacle.h"
#include"buttom.h"
#include"Textureandmusic.h"
using namespace std;
struct rungaming{
    Graphics graphics;
    Texture texture;
    Music music;
    vector<Obstacle> Obs;
    Buttom play, retry,home;
    TTF_Font* font;
    SDL_Color color;
    Obstacle obstacle;
    SDL_Rect shipsize;
    SDL_Event event;
    string current="MENU";
    bool running;
    bool gameOverSoundPlayed;
    int score;
    int spawn;
    void initeverything();
    void gameover();
    void menu();
    void rungame();
    void quitgame();
};
#endif
