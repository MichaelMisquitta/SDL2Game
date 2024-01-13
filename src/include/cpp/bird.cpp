
#include "header/globals.h"
#include <header/bird.h>
#include <SDL2/SDL.h>
#include <math.h> // for sin

bird::bird(SDL_Renderer* rend){
    renderer = rend;
    spriteSheetImage = SDL_LoadBMP("images/patrick.bmp");
    bmpTex = SDL_CreateTextureFromSurface(renderer, spriteSheetImage);
     
}
bird::~bird(){
    

    SDL_FreeSurface(spriteSheetImage);
    
}

void bird::draw(SDL_Renderer* rend){

    // spriteSheetImage = SDL_LoadBMP("images/pipe.bmp");
    // without birdRect, it renders as large as window allows. birdRect crops out what it can fit
    updateAngle();
    SDL_RenderCopyEx(renderer, bmpTex,NULL, &birdRect,angle,NULL,SDL_FLIP_NONE );
    
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

void bird::updateAngle(){
    //y+ is down and clockwise is positive so no need to flip angle sin.
    angle = 180/Global.PI * sin(birdVelocity.y/Global.GAMEVELOCITY); 
}