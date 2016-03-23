#include "Plant.hpp"
#include <ctime>

Plant::Plant(Universe& b, int x, int y,float currentAge):Organism(b,x,y,currentAge), timebuffer(0.0){}

void Plant::update(float dt)
{
    Organism::update(dt);
    if( isDead() ) return;

	float d = 1000/tgrow();
    timebuffer += dt;

    while( timebuffer > d ){
        update_grow();
        timebuffer -= d;
    }
}

void Plant::update_grow(){}

float Plant::getTimebuffer() const{
    return timebuffer;
}
