#include "Plant.hpp"
#include <ctime>

Plant::Plant(Universe& b, int x, int y, int t_lahir):Organism(b,x,y,t_lahir), timebuffer(0.0){}

void Plant::update(float dt)
{
	float d = 1000/tgrow();
    timebuffer += dt;
    while( timebuffer > d ){
        update_grow();
        timebuffer -= d;
    }
}

void Plant::update_grow(){}