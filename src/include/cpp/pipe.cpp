#include "header/pipe.h"
#include <SDL2/SDL.h>
#include <cstdlib>

pipe::pipe (SDL_FPoint birdPos){
    birdPosition = birdPos;
    generateSize();
    generatePosition();
}

void pipe::draw (SDL_Renderer* rend){
    SDL_SetRenderDrawColor(rend,100,0,0,255);
    SDL_RenderFillRect(rend,&pipeRect);

}

void pipe::generateSize(){
    width = 20 + rand() % 40;
    height = 40 + rand() % 40;
    pipeRect.w = width;
    pipeRect.h = height;
    pipePosition.y = float(Global.HEIGHT)*0.75 - height;

}

void pipe::generatePosition(){
    pipePosition.x = int(birdPosition.x) + 100 + rand() % 400;
    pipeRect.x = pipePosition.x; // pipeRect x position is what is drawn
}

void pipe::updatePosition(float dt){
    pipePosition.x -= dt * float(GAMEVELOCITY);
    if (pipePosition.x <= -width){
        generatePosition();
    }
    pipeRect.x = pipePosition.x; // needed since generatePosition is only called when off screen

}