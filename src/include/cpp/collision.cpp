#include <header/collision.h>

collision::collision(){

}

bool collision::isColliding(bird& flappybird,std::list<pipePair*> &pipePairs ){ // pass by reference using & so that copy constructor is not invoked.
    float birdLeft = flappybird.birdRect.x;
    float birdRight = flappybird.birdRect.x + flappybird.birdRect.w;
    float birdHeight = flappybird.birdRect.h;
    float height = flappybird.birdRect.y;
    

    for(std::list<pipePair*>::iterator it = pipePairs.begin(); it != pipePairs.end(); ++it){
         //first dereference it which is pointer to obj, then dereference obj to get value.
        
        if(collisionCheck(height, birdLeft, birdRight,birdHeight, (*it)->pipeTop)){
            return true; // returns true for the first collision and stops checking anything else
        }
        if(collisionCheck(height, birdLeft, birdRight,birdHeight, (*it)->pipeBottom)){
            return true; // returns true for the first collision and stops checking anything else
        }
        
    }
    return false;
}

bool collisionCheck(float height, float birdLeft, float birdRight,float birdHeight, pipe* top){
    bool topOrBottom = top->topOrBottom;
    float pipeLeft = (top)->pipeRect.x;
    float pipeRight = (top)->pipeRect.x + (top)->pipeRect.w;
    if(topOrBottom){
        if(height < ((top)->pipeRect.y +(top)->pipeRect.h )){
            if((birdLeft > pipeLeft && birdLeft < pipeRight) || (birdRight > pipeLeft && birdRight < pipeRight )){
                return true; // if either point of the bird is within the pipe, it is a collision, no matter the case 
            }
        
        }    
    }else{
        if(height > ((top)->pipeRect.y - birdHeight )){
            if((birdLeft > pipeLeft && birdLeft < pipeRight) || (birdRight > pipeLeft && birdRight < pipeRight )){
                return true; // if either point of the bird is within the pipe, it is a collision, no matter the case 
            }
        
        }    
    }
    return false;
    
}