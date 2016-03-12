#include "Eagle.hpp"

Eagle::Eagle(Universe& u, int x, int y,float currentAge):Carnivore(u,x,y,currentAge){}

void Eagle::update(){
	//Update Eagle move
}

char Eagle::ch() const{return 'E';}
float Eagle::speed() const{return 3;}
int Eagle::power() const {return 20;}
int Eagle::age() const{return 60;}