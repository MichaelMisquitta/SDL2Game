#ifndef PIPEPAIR_H
#define PIPEPAIR_H
#include <header/pipe.h>
class pipePair{
    public:
    pipe* pipeTop = NULL;
    pipe* pipeBottom = NULL;
    int separation = 150; // separation between top and bottom pipes
    global Global;
    //methods
    void setPipeHeights();
    void updatePipePositions(float dt);

    //constructor
    pipePair(SDL_Renderer*, int);


};
std::list<pipePair*> genPipePairs(SDL_Renderer *rend);
void updatePipePairs(std::list<pipePair*>, float);
#endif