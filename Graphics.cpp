#include<iostream>
#include<SDL.h>
#include<SDL_ttf.h>
#include<SDL_mixer.h>
#include<SDL_image.h>
#include"defs.h"
#include"Graphics.h"
void ScrollingBackground::setTexture(SDL_Texture* _texture) {
    texture = _texture;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
}

void ScrollingBackground::scroll(int distance) {
    scrollingOffset -= distance;
    if( scrollingOffset < 0 ) { scrollingOffset = width; }
}
void Graphics::logErrorandExit(const char *msg,const char*error)
{
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_ERROR,"%S:%S",msg,error);
        SDL_Quit();
}
void Graphics::init()
{
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0){
        logErrorandExit("SDL_Init",SDL_GetError());
    }
    window=SDL_CreateWindow(WINDOW_TITLE,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
    if(window==nullptr)
        {
            logErrorandExit("CreateWindow",SDL_GetError());
        }
    if(!IMG_Init(IMG_INIT_PNG|IMG_INIT_JPG))
        {
        logErrorandExit("SDL_IMAGE ERROR",SDL_GetError());
        }
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    if (renderer==nullptr)
        {
            logErrorandExit("Createrenderer error",SDL_GetError());
        }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY,"linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
      if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            logErrorandExit( "SDL_mixer could not initialize! SDL_mixer Error: %s", Mix_GetError());
        }
         if (TTF_Init() == -1) {
            logErrorandExit("SDL_ttf could not initialize! SDL_ttf Error: ", TTF_GetError());
        }
    }
    SDL_Texture*Graphics::loadTexture(const char*filename)
    {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_INFO,"Loading %s",filename);
    SDL_Texture*texture=IMG_LoadTexture(renderer,filename);
    if(texture==nullptr){
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION,SDL_LOG_PRIORITY_ERROR,"Load texture %s",IMG_GetError());
    }
    return texture;
    }
    void Graphics::renderTexture(SDL_Texture *texture,int x,int y,int w,int h)
    {
        SDL_Rect dest={x,y,w,h};
        SDL_RenderCopy(renderer,texture,NULL,&dest);
    }
void Graphics::quit()
{
    Mix_Quit();
    IMG_Quit();
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
 void Graphics::render(const ScrollingBackground& background) {
        renderTexture(background.texture, background.scrollingOffset, 0,background.width,background.height);
        renderTexture(background.texture, background.scrollingOffset - background.width, 0,background.width,background.height);
}
Mix_Music *Graphics::loadMusic(const char* path)
    {
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                           "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }
void Graphics::play(Mix_Music *gMusic)
{
    if (gMusic == nullptr) return;
    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic( gMusic, -1 );
    }
    else if( Mix_PausedMusic() == 1 ) {
           Mix_ResumeMusic();
    }
}

Mix_Chunk* Graphics::loadSound(const char* path) {
    Mix_Chunk* gChunk = Mix_LoadWAV(path);
    if (gChunk == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
            "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
    }
}
void Graphics::play(Mix_Chunk* gChunk) {
    if (gChunk != nullptr) {
        Mix_PlayChannel( -1, gChunk, 0 );
    }
}
TTF_Font*Graphics::loadFont(const char* path, int size)
    {
        TTF_Font* gFont = TTF_OpenFont( path, size );
        if (gFont == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Load font %s", TTF_GetError());
        }
    }

SDL_Texture*Graphics::renderText(const char* text, TTF_Font* font, SDL_Color textColor)
    {
        SDL_Surface* textSurface = TTF_RenderText_Solid( font, text, textColor );
        if( textSurface == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Render text surface %s", TTF_GetError());
            return nullptr;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( texture == nullptr ) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, "Create texture from text %s", SDL_GetError());
        }

        SDL_FreeSurface( textSurface );
        return texture;
    }



