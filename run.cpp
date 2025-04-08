#include<SDL.h>
#include"defs.h"
#include"Graphics.h"
#include"Obstacle.h"
#include"buttom.h"
#include"Textureandmusic.h"
#include"run.h"
using namespace std;
bool collisionhandling(SDL_Rect ship,Obstacle &obstacle,vector<Obstacle> Obs,Mix_Chunk*govercome,int&score,Graphics &graphics)
{
    if (ship.x>obstacle.x+OBSTACLE_WIDTH/2&&!obstacle.passed) {
            graphics.play(govercome);
            score++;
            obstacle.passed=true;
            Obs.pop_back();
            return false;
    }
    if (ship.x+ship.w<obstacle.x) return false;
    SDL_Rect top = {obstacle.x, 0, OBSTACLE_WIDTH, obstacle.height };
    SDL_Rect bottom={obstacle.x,obstacle.height+OBSTACLE_GAP,OBSTACLE_WIDTH,SCREEN_HEIGHT-OBSTACLE_GAP-obstacle.height};

    return SDL_HasIntersection(&ship, &top) || SDL_HasIntersection(&ship, &bottom);
}
void rungaming::initeverything(){
    graphics.init();
    texture.loadimage(graphics);
    music.initmusic(graphics);
    font = graphics.loadFont("Purisa-BoldOblique.ttf",48);
    color = {255, 255, 0, 0};
    shipsize={100,20,100,100};
    play.rect={SCREEN_WIDTH/2-100,SCREEN_HEIGHT-200,200,150};
    retry.rect={SCREEN_WIDTH/2-200,SCREEN_HEIGHT-200,200,150};
    home.rect={SCREEN_WIDTH/2,SCREEN_HEIGHT-200,200,150};
    score=0;
    current="MENU";
    gameOverSoundPlayed =false;
    running=true;
    spawn=0;
}
void rungaming::gameover(){
    SDL_RenderClear(graphics.renderer);
    if(!gameOverSoundPlayed){
        graphics.play(music.ggameover);
        gameOverSoundPlayed=true;
    }
    SDL_RenderCopy(graphics.renderer,texture.background,NULL,NULL);
    texture.dislayFont(score,color,graphics,font);
    graphics.renderTexture(texture.gameover,SCREEN_WIDTH/2-250,0,500,400);
    graphics.renderTexture(texture.retrybuttom,SCREEN_WIDTH/2-200,SCREEN_HEIGHT-200,200,150);
    graphics.renderTexture(texture.homebuttom,SCREEN_WIDTH/2,SCREEN_HEIGHT-200,200,150);
    SDL_RenderPresent(graphics.renderer);
}
void rungaming::menu(){
    SDL_RenderCopy(graphics.renderer,texture.background,NULL,NULL);
    graphics.renderTexture(texture.title,SCREEN_WIDTH/2-250,0,500,400);
    graphics.renderTexture(texture.playbuttom,SCREEN_WIDTH/2-100,SCREEN_HEIGHT-200,200,150);
    SDL_RenderPresent(graphics.renderer);
}
void rungaming::rungame(){
    graphics.play(music.gMusic);
    while(running){
    while(SDL_PollEvent(&event)){
            if(event.type==SDL_QUIT) running=false;
            if(event.type==SDL_MOUSEBUTTONDOWN){
                    int mouseclickx=event.button.x;
                    int mouseclicky=event.button.y;
                if(current=="MENU"&&play.isClicked(mouseclickx,mouseclicky)){
                    current="PLAY";
                }else if(current=="GAMEOVER"&&retry.isClicked(mouseclickx,mouseclicky)){
                    current="PLAY";
                    gameOverSoundPlayed=false;
                    score=0;
                    Obslist.clear();
                }else if(current=="GAMEOVER"&&home.isClicked(mouseclickx,mouseclicky)){
                    current="MENU";
                    gameOverSoundPlayed=false;
                    score=0;
                    Obslist.clear();
                }
            }
            if(event.type==SDL_MOUSEMOTION&&current=="PLAY"){
               float ship_speed = 0.3;
                shipsize.y += (event.motion.y - shipsize.y - shipsize.h/2) * ship_speed;
            }

        }
        if(current=="MENU"){
            menu();
        }
        if(current=="GAMEOVER"){
            gameover();
        }
        if(current=="PLAY"){
        if(spawn%OBSTACLE_SPAWN_RATE==0){
            int height=rand()%(SCREEN_HEIGHT-OBSTACLE_GAP);
            Obslist.push_back({SCREEN_WIDTH,height});

        }
        spawn++;
        for (auto& move : Obslist) {
            move.x -= OBSTACLE_SPEED;
        }
            for(auto &obss:Obslist){
                if(collisionhandling(shipsize,obss,Obslist,music.govercome,score,graphics)){
                    current="GAMEOVER";
                    break;
                }
            }
        SDL_RenderClear(graphics.renderer);
        texture.backgroundscoll.scroll(1);
        graphics.render(texture.backgroundscoll);
        texture.dislayFont(score,color,graphics,font);
        SDL_RenderCopy(graphics.renderer,texture.ship,NULL,&shipsize);
        for(auto obstacle:Obslist){
            obstacle.render(graphics,obstacle,texture.Obstacleimage);
        }
        SDL_RenderPresent(graphics.renderer);
        SDL_Delay(13);
        }
    }
}
void rungaming::quitgame(){
    texture.destroyimage();
    graphics.quit();
}
