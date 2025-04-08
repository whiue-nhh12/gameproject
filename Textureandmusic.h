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
    SDL_Texture*homebuttom;
    SDL_Texture*title;
    SDL_Texture*gameover;
    SDL_Color color;
    TTF_Font *font;
    void loadimage(Graphics &graphics);
    void destroyimage();
    void dislayFont(int &score,Graphics &graphics);
};
struct Music{
    Mix_Music *gMusic;
    Mix_Chunk *govercome;
    Mix_Chunk *ggameover;
    void initmusic(Graphics &graphics);
};
#endif
