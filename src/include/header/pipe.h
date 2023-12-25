#ifndef PIPE_H
#define PIPE_H
#include <SDL2/SDL.h>
#include "header/globals.h"
#define GAMEVELOCITY 150

class pipe{

    public:
   
    //constructors
    pipe(SDL_FPoint,bool, SDL_Renderer*);
    ~pipe();
    //variables
    SDL_Renderer* renderer;
    int width = 20;
    int height = 20;
    bool topOrBottom = true; // true for top, false for bottom
    global Global;
    SDL_FPoint pipePosition = {200,0};  //generation of pipes needs to happen ahead of bird position
    SDL_FPoint birdPosition = {0,0};
    SDL_Rect pipeRect = {int(pipePosition.x),int(pipePosition.y),width,height};
    //for sprite
    SDL_Surface* spriteSheetImage = SDL_LoadBMP("images/pipe.bmp");
    SDL_Texture *bmpTex;

    // methods
    void draw(SDL_Renderer*);
    void generateSize();
    void generatePosition();
    void updatePosition(float dt);


};



#endif 