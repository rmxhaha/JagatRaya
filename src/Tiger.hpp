#include "Carnivore.hpp"

#ifndef TIGER_H
#define TIGER_H

class Tiger:public Carnivore{
	public:
	Tiger(Universe& u,int x,int y,float currentAge);
protected:
	void update_logic();
	char ch() const;
	float speed() const;
	int power() const;
	int age() const;
	void interact(Organism*);
};
#endif
