#include <header/pipePair.h>
pipePair::pipePair(SDL_Renderer* rend, int xpos){
    pipeTop = new pipe(true, rend, xpos);
    pipeBottom = new pipe(false, rend, xpos);
    setPipeHeights();
}

void pipePair::setPipeHeights(){
    int deltaHeight = 0;
    int heightTop;
    if ((rand() % 10) < 5 ){
        heightTop = 70 + rand() % 150;
    }else{
        heightTop = 20 + rand() % 30;
    }
    
    int heightBottom = float(Global.HEIGHT)*0.75 - heightTop - separation;
    pipeTop->setHeight(heightTop);
    pipeBottom->setHeight(heightBottom);
}

void pipePair::updatePipePositions(float dt){
    pipeTop->pipePosition.x -= dt * float(GAMEVELOCITY);
    pipeBottom->pipePosition.x -= dt * float(GAMEVELOCITY);
    if (pipeTop->pipePosition.x <= -pipeTop->width - 10){
        setPipeHeights();
        pipeTop->generatePosition(); // must happen afer genSize so right size is used
        pipeBottom->generatePosition();
    }
    pipeTop->pipeRect.x = pipeTop->pipePosition.x; 
    pipeBottom->pipeRect.x = pipeBottom->pipePosition.x; 
}



std::list<pipePair*> genPipePairs(SDL_Renderer *rend){ // generates all the pipes
    int pos = 400;
    std::list<pipePair*> pipePairs;
    for(size_t i = 0; i < 5; ++i){
        pipePairs.push_back(new pipePair(rend, pos));

        pos += 178; // screen width + pipe width + 10 divided by num pipes
    }
    return pipePairs;

}

void updatePipePairs(std::list<pipePair*>& pipePairs,float dt){
    for(std::list<pipePair*>::iterator it = pipePairs.begin(); it != pipePairs.end(); ++it){
        (*it)->updatePipePositions(dt); // pipeTop is a pointer so must be dereferenced
        
        (*it)->pipeTop->draw();
        (*it)->pipeBottom->draw();

    }
}