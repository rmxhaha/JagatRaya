#include "Turtle.hpp"

Turtle::Turtle(Universe& u, int x, int y, int t_lahir):Herbivore(u,x,y,t_lahir){}

void Turtle::update_logic(){
	bool race_event=false;
	if(!race_event)
	{
		if(x!=6&&x!=5)
	    move(goTo(6,5));
	    else
		race_event=true;
	}
	else
	{
		move(direction_t::RIGHT);
	}
		
}
char Turtle::ch() const {
	return 'T';
}
float Turtle::speed() const {
	return 2;
}
int Turtle::power() const {
	return 5;
}
int Turtle::umur() const {
	return 50;
}