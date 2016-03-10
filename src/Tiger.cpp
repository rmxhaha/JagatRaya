#include "Tiger.hpp"

Tiger::Tiger(Universe& u, int x, int y, int t_lahir):Carnivore(u,x,y,t_lahir){}


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
int Tiger::umur() const {
	return 7000;
}

void Tiger::interact(Organism*){
}

