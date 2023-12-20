#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int charc,char *argv[]){

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("test",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *renderer = SDL_CreateRenderer(window,-1,0);
    if (window == NULL){
        std::cout << "window error"<<SDL_GetError();
        return 1;

    }
    SDL_Event windowEvent;

    while(true){
        if(SDL_PollEvent(&windowEvent)){
            if(SDL_QUIT == windowEvent.type){
                break;
            }
        }
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,100,50,250,255);
        SDL_RenderPresent(renderer); // call once per frame to put buffer of drawings to screen
    }
    std::cout << "successs bingus 2";
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}