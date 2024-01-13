#ifndef PIPE_H
#define PIPE_H
#include <SDL2/SDL.h>
#include "header/globals.h"
#include <list>
#define GAMEVELOCITY 150

class pipe{

    public:
   
    //constructors
    pipe(bool, SDL_Renderer*,int);
    ~pipe();
    //variables
    SDL_Renderer* renderer;
    int width = 80;
    int height = 20;
    bool topOrBottom = true; // true for top, false for bottom
    global Global;
    SDL_FPoint pipePosition = {200,0};  //generation of pipes needs to happen ahead of bird position
    
    SDL_Rect pipeRect = {int(pipePosition.x),int(pipePosition.y),width,height};
    //for sprite
    SDL_Surface* spriteSheetImage = SDL_LoadBMP("images/pipe.bmp");
    SDL_Texture *bmpTex;

    // methods
    void draw();
    void setHeight(float height);
    void generatePosition();
   


};




#endif 