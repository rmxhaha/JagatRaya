#include "Turtle.hpp"

#include "Turtle.hpp"

Turtle::Turtle(Universe& u, int x, int y,float currentAge):Herbivore(u,x,y,currentAge){}

void Turtle::update_logic(){
	//Update Tiger move
	move(goRandom());
}
char Turtle::ch() const {
	return 'U';
}
float Turtle::speed() const {
	return 2;
}
int Turtle::power() const {
	return 3;
}
int Turtle::umur() const {
	return 10;
}

void Turtle::interact(Organism*){
}

