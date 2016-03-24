#include "Tiger.hpp"
#include "Deer.hpp"
#include "Horse.hpp"

Tiger::Tiger(Universe& u, int x, int y,float currentAge):Carnivore(u,x,y,currentAge){
    universe->board.SetEl(ch(),y,x);
}


void Tiger::update_logic(){
	//Update Tiger move
	int prey_x;
	int prey_y;
	if( findPrey('D',prey_x,prey_y,x,y)){
		move(goTo(prey_x,prey_y));
	}
	else if( findPrey('H',prey_x,prey_y,x,y)){
		move(goTo(prey_x,prey_y));
	}
	else {
        move(goRandom());
	}
}

//bikin interact
//ganti interact tiger punya class buruan nya
void Tiger::interact(Organism * O){
	if(isA<Deer,Organism>(O)){
		O->forceKill();
	}
	else if(isA<Horse>(O)){
        O->forceKill();
	}
}

char Tiger::ch() const {
	return 'T';
}
float Tiger::speed() const {
	return 5;
}
int Tiger::power() const {
	return 25;
}
int Tiger::age() const {
	return 30000;
}
