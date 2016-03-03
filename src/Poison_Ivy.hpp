#ifndef POISON_IVY_H
#define POISON_IVY_H

#include "Plant.hpp"


class Poison_Ivy : public Plant
{
	public:
	Poison_Ivy(Universe& b, int x, int y, int t_lahir);
	int power();
	float tgrow();
	char ch();
};
#endif
