#include <iostream>
#include <SDL2/SDL.h>
#include <header/bird.h>
#include <header/pipe.h>
//#include "cpp/bird.cpp"


//const int WIDTH = 800, HEIGHT = 600;

 int main(int charc,char *argv[]){

    int b = 255;
    float fpsTime = 0;
    int fps = 60;
    float elapsedMS = 16;
    float dt = 0.016;
    fpsTime = 1.0000/float(fps)*1000.0000;
    Uint64 start = 0;
    Uint64 end = 0;
    global Global;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 0;
    }
    //SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,Global.WIDTH,Global.HEIGHT,0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    bird flappybird;
    pipe pipeBottom(flappybird.birdPosition);

    if (window == NULL){
        std::cout << "window error"<<SDL_GetError();
        return 1;

    }
    SDL_Event Event;

    while(true){
        start = SDL_GetPerformanceCounter();

        if(SDL_PollEvent(&Event)){
            if(SDL_QUIT == Event.type){
                std::cout << "exit success";
                break;
            }
            if(Event.type = SDL_KEYDOWN){
                if(Event.key.keysym.sym == SDLK_SPACE ){
                    flappybird.updateVelocity(true,dt);
                }
            }
            
        }
        
        

        
        SDL_SetRenderDrawColor(renderer,0,0,0,255);
        SDL_RenderClear(renderer);
        
        flappybird.updateVelocity(false,dt);
        flappybird.updatePosition(dt);
        flappybird.draw(renderer);

        pipeBottom.updatePosition(dt);
        pipeBottom.draw(renderer);
        

        end = SDL_GetPerformanceCounter();
        elapsedMS = (end-start) / (float)(SDL_GetPerformanceFrequency()) * 1000.0f;
        
        float delay = 1/float(fps)*1000.0f - elapsedMS;
        dt = 1/float(fps); // delay and elapsed ms both change between frames by 1/60 is the time difference between frames that links them and should be used as dt
        if(delay < 0){
            delay = 1/60.0f*1000.0f; // line is needed to stop delay from going negative when exiting window and causing program crash.
        }
        //std::cout << flappybird.birdVelocity.y << "\n" ;
        //SDL_Delay(floor(1000/float(fps)));
        SDL_Delay(delay);

        SDL_RenderPresent(renderer);
    }
    std::cout << "-successs bingus 2";
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

     return EXIT_SUCCESS;
}