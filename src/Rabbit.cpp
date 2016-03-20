#include "Rabbit.hpp"

Rabbit::Rabbit(Universe& u, int x, int y, int t_lahir):Herbivore(u,x,y,t_lahir){}

void Rabbit::update_logic(){
	if(x!=5||y!=5)
	{
	    move(goTo(5,5));
	}
	    else
	{
		move(direction_t::RIGHT);
	}
}
char Rabbit::ch() const {
	return 'R';
}
float Rabbit::speed() const {
	return 8;
}
int Rabbit::power() const {
	return 6;
}
int Rabbit::umur() const {
	return 30;
}