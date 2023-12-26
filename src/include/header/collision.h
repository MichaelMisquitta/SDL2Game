#ifndef COLLISION_H
#define COLLISION_H
#include <header/pipe.h>
#include <header/bird.h>
#include <list>

class collision{
    //class should take sprite and list of pipes and figure out
    // if sprite is colliding with any of the pipes
    // if collision occurs, game should restart 
    // maybe need way to only count collision once so that
    // counter doesnt increase as long as collision is occuring?

    public:
    //constructors
    collision();
    //variables

    //methods
    bool isColliding(bird ,std::list<pipe*> );


};

bool collisionCheck(bool,float,float,float,float, std::list<pipe*>::iterator);

#endif