#include "Plant.hpp"

#ifndef POISON_IVY_H
#define POISON_IVY_H

class Poison_Ivy : public Plant
{
	public:
	Poison_Ivy(Universe& b, int x, int y,float currentAge);
	protected:
	int power() const;
	float tgrow() const;
	char ch() const;
	void grow()const;
	int age()const;
	void update_grow();
	void interact(Organism*);
};
#endif
