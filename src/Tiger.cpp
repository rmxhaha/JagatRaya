#include "Tiger.hpp"

Tiger::Tiger(Universe& u, int x, int y,float currentAge):Carnivore(u,x,y,currentAge){}


void Tiger::update_logic(){
	//Update Tiger move
	move(goRandom());
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
	return 7000;
}

void Tiger::interact(Organism*){
}

