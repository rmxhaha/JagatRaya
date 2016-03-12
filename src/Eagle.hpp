#include "Carnivore.hpp"

#ifndef EAGLE_H
#define EAGLE_H

class Eagle : public Carnivore {
	public:
	Eagle(Universe& u,int x, int y,float currentAge);
	void update();
	char ch() const ;
	float speed() const ;
	int power() const ;
	int age() const ;
};
#endif