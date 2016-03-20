#include "Turtle.hpp"

Turtle::Turtle(Universe& u, int x, int y, int t_lahir):Herbivore(u,x,y,t_lahir){}

void Turtle::update_logic(){
	//Update Rabbit move
	move(goRandom());
}
char Turtle::ch() const {
	return 'R';
}
float Turtle::speed() const {
	return 7;
}
int Turtle::power() const {
	return 4;
}
int Turtle::umur() const {
	return 30;
}