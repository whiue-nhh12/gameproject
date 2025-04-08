#include<SDL.h>
#include<string>
#include<SDL_image.h>
#include"defs.h"
#include"Graphics.h"
#include"Textureandmusic.h"
using namespace std;
void Texture::loadimage(Graphics &graphics){
    backgroundscoll.setTexture(graphics.loadTexture("ocean_tiled.jpg"));
    background=graphics.loadTexture("ocean_scene.jpg");
    ship=graphics.loadTexture("ship.png");
    Obstacleimage=graphics.loadTexture("obstacle1-removebg-preview.png");
    playbuttom=graphics.loadTexture("playbuttom.png");
    retrybuttom=graphics.loadTexture("retrybuttom.png");
    homebuttom=graphics.loadTexture("home.png");
    title=graphics.loadTexture("title.png");
    gameover=graphics.loadTexture("gameover.png");
    font = graphics.loadFont("Purisa-BoldOblique.ttf",48);
    color = {255, 255, 0, 0};
}
void Texture::destroyimage(){
    SDL_DestroyTexture( ship );
    ship = NULL;
    SDL_DestroyTexture( backgroundscoll.texture );
    backgroundscoll.texture = NULL;
    SDL_DestroyTexture(background);
    background=NULL;
    SDL_DestroyTexture(Obstacleimage);
    Obstacleimage=NULL;
    SDL_DestroyTexture(gameover);
    gameover=NULL;
    SDL_DestroyTexture(playbuttom);
    playbuttom=NULL;
    SDL_DestroyTexture(homebuttom);
    homebuttom=NULL;
    SDL_DestroyTexture(retrybuttom);
    retrybuttom=NULL;
    SDL_DestroyTexture(title);
    title=NULL;
}
void Texture::dislayFont(int &score,Graphics &graphics){
    string scorestr="SCORE: "+to_string(score);
    SDL_Texture* helloText = graphics.renderText(scorestr.c_str(),font,color);
    graphics.renderTexture(helloText,SCREEN_WIDTH-200,0,Font_Width,Font_Height);
}
void Music::initmusic(Graphics &graphics){
    gMusic = graphics.loadMusic("thememusic.mp3");
    govercome = graphics.loadSound("purchase-succesful-ingame.wav");
    ggameover = graphics.loadSound("negative_beeps-6008.wav");
}
