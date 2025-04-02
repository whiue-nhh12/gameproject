#ifndef _Texturandmusic_h
#define _Texturandmusic_h
#include"Graphics.h"
struct Texture{
    ScrollingBackground backgroundscoll;
    SDL_Texture *background;
    SDL_Texture *ship;
    SDL_Texture*Obstacleimage;
    SDL_Texture*playbuttom;
    SDL_Texture*retrybuttom;
    SDL_Texture*title;
    SDL_Texture*gameover;
    void loadimage(Graphics &graphics);
    void destroyimage();
    void dislayFont(int &score,SDL_Color color,Graphics graphics,TTF_Font *font);
};
struct Music{
    Mix_Music *gMusic;
    Mix_Chunk *govercome;
    Mix_Chunk *ggameover;
    void initmusic(Graphics &graphics);
};
#endif
