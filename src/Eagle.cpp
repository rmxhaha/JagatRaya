#include "Eagle.hpp"

Eagle::Eagle(Universe& u, int x, int y, int t_lahir):Carnivore(u,x,y,t_lahir){}

void Eagle::update(){
	//Update Eagle move
}
char Eagle::ch(){
	return 'E';
}
float Eagle::speed(){
	return 3;
}
int Eagle::power(){
	return 20;
}
int Eagle::umur(){
	return 60;
}