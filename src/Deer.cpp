#include "Deer.hpp"
#include "Grass.hpp"

Deer::Deer(Universe& u, int x, int y, int t_lahir):Herbivore(u,x,y,t_lahir){}

void Deer::update_logic(){
	//Update Tiger move
	int prey_x;
	int prey_y;
	if(findPrey('T',prey_x,prey_y,x,y)){
		move(avoid(prey_x,prey_y));
	}
	else{
		if(findPrey('D',prey_x,prey_y,x,y)){
			move(goTo(prey_x,prey_y));
		}
		else{
			move(goRandom());
		}
	}
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
int Deer::age() const {
	return 60000000;
}

void Deer::interact(Organism* O){
   if(isA<Grass,Organism>(O)){
		O->forceKill();
	}
}
