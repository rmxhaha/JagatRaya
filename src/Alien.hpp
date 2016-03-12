#include "Carnivore.hpp"

#ifndef ALIEN_H
#define ALIEN_H

class Alien:public Carnivore{
	public:
	Alien(Universe& u,int x, int y,float currentAge);
	void update();
	char ch() const ;
	float speed() const ;
	int power() const ;
	int age() const ;
};
#endif