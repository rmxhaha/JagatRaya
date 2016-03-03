#include "Eagle.hpp"

Eagle::Eagle(Universe& u, int x, int y, int t_lahir):Carnivore(u,x,y,t_lahir){}

void Eagle::update(){
	//Update Eagle move
}

char Eagle::ch() const{return 'E';}
float Eagle::speed() const{return 3;}
int Eagle::power() const {return 20;}
int Eagle::umur() const{return 60;}