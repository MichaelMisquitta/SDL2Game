#include <header/collision.h>

collision::collision(){

}

bool collision::isColliding(bird flappybird,std::list<pipe*> pipes ){
    float birdLeft = flappybird.birdRect.x;
    float birdRight = flappybird.birdRect.x + flappybird.birdRect.w;
    float birdHeight = flappybird.birdRect.h;
    float height = flappybird.birdRect.y;
    bool topOrBottom;

    for(std::list<pipe*>::iterator it = pipes.begin(); it != pipes.end(); ++it){
        topOrBottom = (*it)->topOrBottom; //first dereference it which is pointer to obj, then dereference obj to get value.
        
        if(collisionCheck(topOrBottom,height, birdLeft, birdRight,birdHeight, it)){
            return true; // returns true for the first collision and stops checking anything else
        }
        
    }
    return false;
}

bool collisionCheck(bool topOrBottom,float height, float birdLeft, float birdRight,float birdHeight, std::list<pipe*>::iterator it){
    float pipeLeft = (*it)->pipeRect.x;
    float pipeRight = (*it)->pipeRect.x + (*it)->pipeRect.w;
    if(topOrBottom){
        if(height < ((*it)->pipeRect.y +(*it)->pipeRect.h )){
            if((birdLeft > pipeLeft && birdLeft < pipeRight) || (birdRight > pipeLeft && birdRight < pipeRight )){
                return true; // if either point of the bird is within the pipe, it is a collision, no matter the case 
            }
        
        }    
    }else{
        if(height > ((*it)->pipeRect.y - birdHeight )){
            if((birdLeft > pipeLeft && birdLeft < pipeRight) || (birdRight > pipeLeft && birdRight < pipeRight )){
                return true; // if either point of the bird is within the pipe, it is a collision, no matter the case 
            }
        
        }    
    }
    return false;
    
}