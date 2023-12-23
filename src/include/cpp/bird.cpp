

#include <header/bird.h>
#include <SDL2/SDL.h>

bird::bird(){


}

void bird::draw(SDL_Renderer* rend){
    SDL_SetRenderDrawColor(rend,0,100,0,255);
    SDL_RenderFillRect(rend,&birdRect);
    
}

void bird::updatePosition(float dt){
    birdPosition.y += dt*birdVelocity.y;
    if(birdPosition.y > float(HEIGHT)*0.75){
        birdPosition.y = HEIGHT*0.75;
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