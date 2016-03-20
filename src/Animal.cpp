#include "Animal.hpp"
#include "Direction.hpp"



Animal::Animal(Universe& u, int x, int y, float currentAge) : Organism(u,x,y,currentAge), timebuffer(0.0) {
}

void Animal::update(float dt)
{
    Organism::update(dt);
    if( isDead() ) return;

    float d = 1000/speed();
    timebuffer += dt;

    while( timebuffer > d ){
        update_logic();
        timebuffer -= d;
    }
}
void Animal::update_logic(){}

direction_t Animal::avoid( int tx, int ty )
{
    if( tx < x ){ // run right
        if( ty < y ) // run up
            return direction_t::UP_RIGHT;
        if( ty > y ) // run down
            return direction_t::DOWN_RIGHT;
        return direction_t::RIGHT;
    }
    if( x < tx ){ // run left
        if( ty < y ) // run up
            return direction_t::UP_LEFT;
        if( ty > y ) // run down
            return direction_t::DOWN_LEFT;
        return direction_t::LEFT;
    }
    if( ty < y ) // run up
        return direction_t::UP;
    if( ty > y ) // run down
        return direction_t::DOWN;
    // on the same coor
    return direction_t::UP_LEFT;
}

direction_t Animal::goTo( int tx, int ty ){
    if( tx > x ){ // run right
        if( ty > y ) // run up
            return direction_t::UP_RIGHT;
        if( ty < y ) // run down
            return direction_t::DOWN_RIGHT;
        return direction_t::RIGHT;
    }
    if( x > tx ){ // run left
        if( ty > y ) // run up
            return direction_t::UP_LEFT;
        if( ty < y ) // run down
            return direction_t::DOWN_LEFT;
        return direction_t::LEFT;
    }
    if( ty > y ) // run up
        return direction_t::UP;
    if( ty < y ) // run down
        return direction_t::DOWN;
    return direction_t::NO_WHERE;
}
direction_t Animal::goRandom(){
    int d = rand() % 8;
    switch(d){
    case 0: return direction_t::UP;
    case 1: return direction_t::DOWN;
    case 2: return direction_t::LEFT;
    case 3: return direction_t::RIGHT;
    case 4: return direction_t::UP_LEFT;
    case 5: return direction_t::UP_RIGHT;
    case 6: return direction_t::DOWN_LEFT;
    case 7: return direction_t::DOWN_RIGHT;
    default : return direction_t::UP;
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


    // plus GetW getH is for negative number mod
    int tx = x + dx + universe->board.GetW();
    int ty = y + dy + universe->board.GetH();

    // update The board here
    tx %= universe->board.GetW();
    ty %= universe->board.GetH();


    universe->board.DelEl(ch(),x,y);
    universe->board.SetEl(ch(),tx,ty);
    universe->notifyMovement(this);
    x=  tx;
    y = ty;
}


class Target {
    public:
	Target(){
    	x = 0;
    	y = 0;
    	distance = 0;
	}
	int x,y,distance;
};

bool Animal::findPrey(char prey_ch,int & prey_x,int & prey_y,int predator_x,int predator_y){
	vector<Target> vec;
	Board& board = universe->board;
	int i = 0;
	int j;
	Target T;
	
	while(i<board.GetH()){
		j=0;
		while(j<board.GetW()){
			if(board.GetEl(i,j).find(prey_ch)<board.GetEl(i,j).length()){
				T.x = i;
				T.y = j;
				T.distance = (predator_x-T.x)*(predator_x-T.x) + (predator_y-T.y)*(predator_y-T.y);
				vec.push_back(T);
			}
			j++;
		}
		i++;
	}
	i=1;
	if(vec.size()>0){
		int min = vec[0].distance;
		prey_x=vec[0].x;
		prey_y=vec[0].y;
		while(i<vec.size()){
			if(vec[i].distance<min){
				prey_x=vec[i].x;
				prey_y=vec[i].y;
			}
			i++;
		}	
		return true;
	}
	else{
		return false;
	}
}
