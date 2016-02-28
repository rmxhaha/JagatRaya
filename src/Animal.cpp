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

Animal::move(){
    int dx = 0, dy = 0;

    switch( direction ){
	case NO_WHERE:      break;
	case UP:        dy = 1; break;
	case DOWN:      dy = -1; break;
	case LEFT:      dx = -1; break;
	case RIGHT:     dx = 1; break;
	case UP_LEFT:   dy = 1; dx = -1; break;
	case DOWN_LEFT: dy = -1; dx = -1; break;
	case UP_RIGHT:  dy = 1; dx = 1; break;
	case DOWN_RIGHT: dy = -1; dx = 1; break;
    }

    int tx = x + dx;
    int ty = y + dy;

    // update The board here


}
