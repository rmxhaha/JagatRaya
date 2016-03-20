#include "Rabbit.hpp"

Rabbit::Rabbit(Universe& u, int x, int y, int t_lahir):Herbivore(u,x,y,t_lahir){}

void Rabbit::update_logic(){
	//Update Rabbit move
	move(goRandom());
}
char Rabbit::ch() const {
	return 'R';
}
float Rabbit::speed() const {
	return 7;
}
int Rabbit::power() const {
	return 4;
}
int Rabbit::umur() const {
	return 30;
}