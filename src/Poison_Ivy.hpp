#include "Plant.cpp"

#ifndef POISON_IVY_H
#define POISON_IVY_H

class Poison_Ivy : public Plant 
{
	public:
	Poison_Ivy(Board&, int x, int y, int t_lahir);
	protected:
	void power();
	void tgrow();
	void ch();
};
#endif