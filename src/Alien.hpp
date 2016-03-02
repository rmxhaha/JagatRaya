#include "Carnivore.hpp"

#ifndef ALIEN_H
#define ALIEN_H

class Alien:public Carnivore{
	public:
	Alien(Board& b, int x, int y, int t_lahir);
	void update();
	char ch();
	float speed();
	int power();
	int umur();
};
#endif