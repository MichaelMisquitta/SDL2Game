#ifndef PIPE_H
#define PIPE_H
#include <SDL2/SDL.h>
#include "header/globals.h"
#define GAMEVELOCITY 150

class pipe{

    public:
    //constructors
    pipe(SDL_FPoint);
    //variables
    int width = 0;
    int height = 0;
    global Global;
    SDL_FPoint pipePosition = {200,0};  //generation of pipes needs to happen ahead of bird position
    SDL_FPoint birdPosition = {0,0};
    SDL_Rect pipeRect = {int(pipePosition.x),int(pipePosition.y),width,height};


    // methods
    void draw(SDL_Renderer*);
    void generateSize();
    void generatePosition();
    void updatePosition(float dt);


};



#endif 