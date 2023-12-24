#ifndef BIRD_H
#define BIRD_H
#include "header/globals.h"
#include <SDL2/SDL.h>
#define GRAVITY 600
#define SIZE 20

class bird{

    public:
    //bird variables
   
    SDL_FPoint birdPosition = {200.0,0.0}; //float needed for accurate position
    SDL_FPoint birdVelocity = {0.00,0.00}; //float needed for accurate position
    global Global;
    //constructors
    bird();
    SDL_Rect birdRect = {int(birdPosition.x),int(birdPosition.y),SIZE,SIZE};

    //bird functions
    void draw(SDL_Renderer*);
    void updatePosition(float dt);
    void updateVelocity(bool ,float);

    
    
};

#endif