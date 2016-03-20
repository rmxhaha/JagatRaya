#include "Carnivore.hpp"

#ifndef ALIEN_H
#define ALIEN_H

class Alien:public Carnivore{
	public:
	Alien(Universe& u,int x, int y,float currentAge);
	void update_logic();
	bool find(int & prey_x,int & prey_y,int predator_x,int predator_y);
	void interact(Organism * O);
	char ch() const ;
	float speed() const ;
	int power() const ;
	int age() const ;
};
#endif
