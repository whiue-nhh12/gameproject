#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include"Graphics.h"
#include"buttom.h"
bool Buttom::isClicked(int x,int y)
{
    return (x>=rect.x&&x<=rect.x+rect.w&&y>=rect.y&&y<=rect.y+rect.h);
}
