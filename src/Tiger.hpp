#include "Carnivore.hpp"

#ifndef TIGER_H
#define TIGER_H

class Tiger:public Carnivore{
	public:
	Tiger(Board& b,int x,int y,int t_lahir);
	void update();
	char ch();
	float speed();
	int power();
	int umur();
};
#endif