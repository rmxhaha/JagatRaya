#include "Animal.hpp"
#include "Direction.hpp"



Animal::Animal(Universe& u, int x, int y, int t_lahir) : Organism(u,x,y,t_lahir) {
}

direction_t Animal::avoid( int tx, int ty )
{
    if( tx < x ){ // run right
        if( ty < y ) // run up
            return direction_t::UP_RIGHT;
        else if( ty > y ) // run down
            return direction_t::DOWN_RIGHT;
        else
            return direction_t::RIGHT;
    }
    else if( x < tx ){ // run left
        if( ty < y ) // run up
            return direction_t::UP_LEFT;
        else if( ty > y ) // run down
            return direction_t::DOWN_LEFT;
        else
            return direction_t::LEFT;
    }
    else {
        if( ty < y ) // run up
            return direction_t::UP;
        else if( ty > y ) // run down
            return direction_t::DOWN;
        else{
            // on the same coor
            return direction_t::UP_LEFT;
        }
    }
}

direction_t Animal::goTo( int tx, int ty ){
    if( tx > x ){ // run right
        if( ty > y ) // run up
            return direction_t::UP_RIGHT;
        else if( ty < y ) // run down
            return direction_t::DOWN_RIGHT;
        else
            return direction_t::RIGHT;
    }
    else if( x > tx ){ // run left
        if( ty > y ) // run up
            return direction_t::UP_LEFT;
        else if( ty < y ) // run down
            return direction_t::DOWN_LEFT;
        else
            return direction_t::LEFT;
    }
    else {
        if( ty > y ) // run up
            return direction_t::UP;
        else if( ty < y ) // run down
            return direction_t::DOWN;
        else{
            // on the same coor
            // just stop
        }
    }
}

void Animal::move(direction_t direction){
    int dx = 0, dy = 0;

    switch( direction ){
	case direction_t::NO_WHERE:      break;
	case direction_t::UP:        dy = 1; break;
	case direction_t::DOWN:      dy = -1; break;
	case direction_t::LEFT:      dx = -1; break;
	case direction_t::RIGHT:     dx = 1; break;
	case direction_t::UP_LEFT:   dy = 1; dx = -1; break;
	case direction_t::DOWN_LEFT: dy = -1; dx = -1; break;
	case direction_t::UP_RIGHT:  dy = 1; dx = 1; break;
	case direction_t::DOWN_RIGHT: dy = -1; dx = 1; break;
    }

    int tx = x + dx;
    int ty = y + dy;

    // update The board here


}
