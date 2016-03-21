#include "Rabbit.hpp"

Rabbit::Rabbit(Universe& u, int x, int y,float currentAge):Herbivore(u,x,y,currentAge){
    universe->board.SetEl(ch(),x,y);
}

void Rabbit::update_logic(){
	//Update Tiger move
	move(goRandom());
}
char Rabbit::ch() const {
	return 'R';
}
float Rabbit::speed() const {
	return 7;
}
int Rabbit::power() const {
	return 3;
}
int Rabbit::umur() const {
	return 60;
}

void Rabbit::interact(Organism*){
}
