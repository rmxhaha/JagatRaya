#include "Horse.hpp"

Horse::Horse(Universe& u, int x, int y, int t_lahir):Herbivore(u,x,y,t_lahir){}

void Horse::update_logic(){
	//Update Tiger move
	move(goRandom());
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
int Horse::umur() const {
	return 60;
}

void Horse::interact(Organism*){
}
