#include "Alien.hpp"

Alien::Alien(Universe& u, int x, int y, int t_lahir):Carnivore(u,x,y,t_lahir){}

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
