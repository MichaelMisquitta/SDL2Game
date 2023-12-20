#include <iostream>
#include <SDL2/SDL.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int charc,char *argv[]){

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("test",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,WIDTH,HEIGHT,SDL_WINDOW_ALLOW_HIGHDPI);

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
    }
    std::cout << "successs bingus";
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}