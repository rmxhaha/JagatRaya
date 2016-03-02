#include "Tiger.hpp"

Tiger::Tiger(Universe& u, int x, int y, int t_lahir):Carnivore(u,x,y,t_lahir){}
,
void Tiger::update(){
	//Update Tiger move
}
char Tiger::ch(){
	return 'T';
}
float Tiger::speed(){
	return 5;
}
int Tiger::power(){
	return 25;
}
int Tiger::umur(){
	return 70;
}
