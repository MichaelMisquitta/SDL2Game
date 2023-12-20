#include <iostream>
#include <SDL2/SDL.h>
#include <time.h>
#include <cmath>
#include <cstdlib>

const int WIDTH = 800, HEIGHT = 600;

int main(int charc,char *argv[]){

    int b = 255;
    float fpsTime = 0;
    int fps = 30;
    fpsTime = 1.0000/float(fps)*1000.0000;
    Uint64 start = 0;
    Uint64 end = 0;
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,0);
    if (window == NULL){
        std::cout << "window error"<<SDL_GetError();
        return 1;

    }
    SDL_Event windowEvent;

    while(true){
        start = SDL_GetPerformanceCounter();

        if(SDL_PollEvent(&windowEvent)){
            if(SDL_QUIT == windowEvent.type){
                std::cout << "successs bingus 2";
                break;
            }
        }

        SDL_RenderClear(renderer);

        b -= 1;
        if (b < 0){
            b = 255;
        }
        SDL_SetRenderDrawColor(renderer,100,50,b,255);
        SDL_RenderPresent(renderer); // call once per frame to put buffer of drawings to screen

        end = SDL_GetPerformanceCounter();
        float elapsedMS = (end-start) / (float)(SDL_GetPerformanceFrequency()) * 1000.0f;

        SDL_Delay(floor(fpsTime-elapsedMS));
    }
    std::cout << "successs bingus 2";
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}