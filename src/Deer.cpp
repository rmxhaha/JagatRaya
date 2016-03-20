#include "Deer.hpp"

Deer::Deer(Universe& u, int x, int y, int t_lahir):Herbivore(u,x,y,t_lahir){}

void Deer::update_logic(){
	//Update Tiger move
	move(goRandom());
}
char Deer::ch() const {
	return 'D';
}
float Deer::speed() const {
	return 5;
}
int Deer::power() const {
	return 5;
}
int Deer::umur() const {
	return 60;
}

void Deer::interact(Organism*){
}
