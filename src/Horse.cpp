#include "Horse.hpp"
#include "Grass.hpp"
#include "Poison_Ivy.hpp"
Horse::Horse(Universe& u, int x, int y,float currentAge):Herbivore(u,x,y,currentAge){
    universe->board.SetEl(ch(),y,x);
}

void Horse::update_logic(){
	//Update Tiger move
	int prey_x;
	int prey_y;
	if(!findPrey('G',prey_x,prey_y,x,y)&&!findPrey('P',prey_x,prey_y,x,y)){
		move(goRandom());
	}
	else{
		move(goTo(prey_x,prey_y));
	}
}
char Horse::ch() const {
	return 'H';
}
float Horse::speed() const {
	return 5;
}
int Horse::power() const {
	return 5;
}
int Horse::age() const {
	return 30000;
}

void Horse::interact(Organism* O){
    if(isA<Grass>(O)){
		O->forceKill();
	}
}
