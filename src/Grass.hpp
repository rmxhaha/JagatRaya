#include "Plant.cpp"

#ifndef GRASS_H
#define GRASS_H

class Grass : public Plant {
	public:
		Grass(Board&, int x, int y, int t_lahir);
	protected:
		void power();
		float tgrow();
		char ch();
};
#endif