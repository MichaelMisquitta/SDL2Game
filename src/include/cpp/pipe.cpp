#include "header/pipe.h"
#include <SDL2/SDL.h>
#include <cstdlib>

pipe::pipe (SDL_FPoint birdPos, bool location){
    topOrBottom = location; // set value first otherwise rect starts at y = 0 for bottom 
    birdPosition = birdPos;
    generateSize();
    generatePosition();
    
}

void pipe::draw (SDL_Renderer* rend){
    SDL_SetRenderDrawColor(rend,100,0,0,255);
    SDL_RenderFillRect(rend,&pipeRect);

}

void pipe::generateSize(){
    width = 50 + rand() % 100;
    height = 60 + rand() % 150;
    pipeRect.w = width;
    pipeRect.h = height;
    

}

void pipe::generatePosition(){
    pipePosition.x = int(birdPosition.x) + 100 + rand() % 400;
    pipeRect.x = pipePosition.x; // pipeRect x position is what is drawn
    if (!topOrBottom){
        pipePosition.y = float(Global.HEIGHT)*0.75 - height;
        pipeRect.y = pipePosition.y;
    }
}

void pipe::updatePosition(float dt){
    pipePosition.x -= dt * float(GAMEVELOCITY);
    if (pipePosition.x <= -width - 10){
        generateSize();
        generatePosition(); // must happen afer genSize so right size is used
        
    }
    pipeRect.x = pipePosition.x; // needed since generatePosition is only called when off screen

}