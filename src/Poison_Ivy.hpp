#include "Plant.hpp"

#ifndef POISON_IVY_H
#define POISON_IVY_H

class Poison_Ivy : public Plant 
{
	public:
	Poison_Ivy(Universe& b, int x, int y, int t_lahir);
	protected:
	int power() const;
	float tgrow() const;
	char ch() const;
	void grow()const;
	int umur()const;
	void update_grow();
};
#endif