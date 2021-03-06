#include "Deer.hpp"
#include "Grass.hpp"

Deer::Deer(Universe& u, int x, int y, float currentAge):Herbivore(u,x,y,currentAge){
    universe->board.SetEl(ch(),y,x);
}

void Deer::update_logic(){
	//Update Tiger move
	int prey_x;
	int prey_y;
	if(findPrey('T',prey_x,prey_y,x,y)){
            cout << prey_x << " " << prey_y;
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
	return 30000;
}

void Deer::interact(Organism* O){
   if(isA<Grass,Organism>(O)){
		O->forceKill();
	}
}
