#include "Eagle.hpp"
#include "Rabbit.hpp"
#include "Turtle.hpp"
Eagle::Eagle(Universe& u, int x, int y,float currentAge):Carnivore(u,x,y,currentAge){
}

void Eagle::update_logic(){
	//Update Eagle move
	if(y==0 && x!=universe->board.GetW()-1){
		move(direction_t::RIGHT);
	}
	else if(y==universe->board.GetH()-1 && x!=0){
		move(direction_t::LEFT);
	}
	else{
		if(x==0){
			move(direction_t::DOWN);
		}
		else if(x==universe->board.GetW()-1){
			move(direction_t::UP);
		}
		else{
			move(direction_t::LEFT);
		}
	}
}

void Eagle::interact(Organism * O){
    if(isA<Rabbit,Organism>(O)){
		O->forceKill();
	}
	if(isA<Turtle,Organism>(O)){
		O->forceKill();
	}
}
char Eagle::ch() const{return 'E';}
float Eagle::speed() const{return 3;}
int Eagle::power() const {return 20;}
int Eagle::age() const{return 600000;}
