#ifndef GRASS_H
#define GRASS_H

#include "Plant.hpp"

class Grass : public Plant {
	public:
		Grass(Universe&, int x, int y, int t_lahir);
		int power();
		float tgrow();
		char ch();
};
#endif
