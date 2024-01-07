#include "header/pipe.h"
#include <SDL2/SDL.h>
#include <cstdlib>
#include <header/globals.h>

pipe::pipe( bool location, SDL_Renderer* rend, int xpos){
    topOrBottom = location; // set value first otherwise rect starts at y = 0 for bottom 
    
    
    renderer = rend;
    spriteSheetImage = SDL_LoadBMP("images/pipe.bmp");
    bmpTex = SDL_CreateTextureFromSurface(renderer, spriteSheetImage);
    // if (!topOrBottom){
    //     pipePosition.y = float(Global.HEIGHT)*0.75 - height;
    //     pipeRect.y = pipePosition.y;
    // }
    pipePosition.x = xpos;
}
pipe::~pipe(){

}

void pipe::draw (){

    auto flip = [this]{
        if(this->topOrBottom){
            return SDL_FLIP_VERTICAL;
        }else{
            return SDL_FLIP_NONE;
        }


    };
    // without birdRect, it renders as large as window allows. birdRect crops out what it can fit
    SDL_RenderCopyEx(renderer, bmpTex,NULL, &pipeRect,0,NULL, flip());

    //SDL_SetRenderDrawColor(rend,100,0,0,255);
    //SDL_RenderFillRect(rend,&pipeRect);

}

void pipe::setHeight(float height){
    
    pipeRect.h = height;
    if(this->topOrBottom == false){
        pipeRect.y = float(Global.HEIGHT) * 0.75- height;
    }
    

}

void pipe::generatePosition(){
    pipePosition.x = 800;
    pipeRect.x = pipePosition.x; // pipeRect x position is what is drawn
    
}



