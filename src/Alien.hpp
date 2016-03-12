#include "Carnivore.hpp"

#ifndef ALIEN_H
#define ALIEN_H

class Alien:public Carnivore{
	public:
	Alien(Universe& u,int x, int y, int t_lahir);
	void update();
	char ch() const ;
	float speed() const ;
	int power() const ;
	int age() const ;
};
#endif