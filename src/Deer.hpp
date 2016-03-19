#include "Herbivore.hpp"

#ifndef DEER_H
#define DEER_H

class Deer:public Herbivore{
	public:
	Deer(Universe& u,int x,int y,int t_lahir);
protected:
	void update_logic();
	char ch() const;
	float speed() const;
	int power() const;
	int umur() const;
	void interact(Organism*);
};
#endif
