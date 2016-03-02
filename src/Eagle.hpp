#include "Carnivore.hpp"

#ifndef EAGLE_H
#define EAGLE_H

class Eagle : public Carnivore {
	public:
	Eagle(Universe& u,int x, int y, int t_lahir);
	void update();
	char ch();
	float speed();
	int power();
	int umur();
};
#endif