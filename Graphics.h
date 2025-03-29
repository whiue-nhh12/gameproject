#ifndef _Graphics_h
#define _Graphics_h
#include<SDL.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<SDL_image.h>
#include"defs.h"
struct ScrollingBackground {
    SDL_Texture* texture;
    int scrollingOffset = 0;
    int width, height;
    void setTexture(SDL_Texture* _texture);
    void scroll(int distance);
};
struct Graphics{
    SDL_Renderer*renderer;
    SDL_Window *window;
    void logErrorandExit(const char *msg,const char*error);
    void init();
    SDL_Texture*loadTexture(const char*filename);
    void renderTexture(SDL_Texture *texture,int x,int y,int w,int h);
    void quit();
    void render(const ScrollingBackground& background);
    Mix_Music *loadMusic(const char* path);
    void play(Mix_Music *gMusic);
    Mix_Chunk* loadSound(const char* path);
    void play(Mix_Chunk* gChunk);
    TTF_Font*loadFont(const char* path, int size);
    SDL_Texture*renderText(const char* text, TTF_Font* font, SDL_Color textColor);
};

#endif // _Graphics_h

