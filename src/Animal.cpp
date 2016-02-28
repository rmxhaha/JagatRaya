#include "Animal.hpp"
#include "Direction.hpp"



Animal::Animal(Board& b, int x, int y, int t_lahir) : MahklupHidup(b,x,y,t_lahir), direction(direction_t::NO_WHERE) {
}

void Animal::avoid( int tx, int ty )
{
    if( tx < x ){ // run right
        if( ty < y ) // run up
            direction = direction_t::UP_RIGHT;
        else if( ty > y ) // run down
            direction = direction_t::DOWN_RIGHT;
        else
            direction = direction_t::RIGHT;
    }
    else if( x < tx ){ // run left
        if( ty < y ) // run up
            direction = direction_t::UP_LEFT;
        else if( ty > y ) // run down
            direction = direction_t::DOWN_LEFT;
        else
            direction = direction_t::LEFT;
    }
    else {
        if( ty < y ) // run up
            direction = direction_t::UP;
        else if( ty > y ) // run down
            direction = direction_t::DOWN;
        else{
            // on the same coor
            direction = direction_t::UP_LEFT;
        }
    }
}

void Animal::goTo( int tx, int ty ){
    if( tx > x ){ // run right
        if( ty > y ) // run up
            direction = direction_t::UP_RIGHT;
        else if( ty < y ) // run down
            direction = direction_t::DOWN_RIGHT;
        else
            direction = direction_t::RIGHT;
    }
    else if( x > tx ){ // run left
        if( ty > y ) // run up
            direction = direction_t::UP_LEFT;
        else if( ty < y ) // run down
            direction = direction_t::DOWN_LEFT;
        else
            direction = direction_t::LEFT;
    }
    else {
        if( ty > y ) // run up
            direction = direction_t::UP;
        else if( ty < y ) // run down
            direction = direction_t::DOWN;
        else{
            // on the same coor
            // just stop
        }
    }
}

void Animal::move(){
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
