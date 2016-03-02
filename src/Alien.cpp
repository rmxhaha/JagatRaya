#include "Alien.hpp"

Alien::Alien(Board& b, int x, int y, int t_lahir):Carnivore(b,x,y,t_lahir){}

void Alien::update(){
	//Update Alien move
}
char Alien::ch(){
	return '@';
}
float Alien::speed(){
	return 1;
}
int Alien::power(){
	return 50;
}
int Alien::umur(){
	return 100;
}
