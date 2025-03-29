#ifndef _buttom_h
#define _buttom_h
#include<iostream>
struct Buttom
{
    SDL_Rect rect;
    bool isClicked(int x,int y);
};
#endif
