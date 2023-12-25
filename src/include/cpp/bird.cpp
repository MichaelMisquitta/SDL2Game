
#include "header/globals.h"
#include <header/bird.h>
#include <SDL2/SDL.h>

bird::bird(SDL_Renderer* rend){
    renderer = rend;
    bmpTex = SDL_CreateTextureFromSurface(renderer, spriteSheetImage);
     
}
bird::~bird(){
    SDL_FreeSurface(spriteSheetImage);
    //free(renderer); taken care off by destroyRenderer in main
}

void bird::draw(SDL_Renderer* rend){

    spriteSheetImage = SDL_LoadBMP("images/pipe.bmp");
    // without birdRect, it renders as large as window allows. birdRect crops out what it can fit
    
    SDL_RenderCopyEx(renderer, bmpTex,NULL, &birdRect,0,NULL,SDL_FLIP_NONE );
    
    //SDL_SetRenderDrawColor(rend,0,100,0,255);
    //SDL_RenderFillRect(rend,&birdRect);
    
}

void bird::updatePosition(float dt){
    birdPosition.y += dt*birdVelocity.y;
    if(birdPosition.y > float(Global.HEIGHT)*0.75 - SIZE){
        birdPosition.y = Global.HEIGHT*0.75 - SIZE;
        birdVelocity.y = 0;
    }
    birdRect.y = birdPosition.y; //coordinates of bird rect are used for position when drawing
}
void bird::updateVelocity(bool jumped,float dt){
    if (jumped){
        birdVelocity.y = float(-300);
    }else{
        birdVelocity.y += float(GRAVITY)*dt;
        
    }
    
}