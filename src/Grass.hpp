#ifndef GRASS_H
#define GRASS_H

#include "Plant.hpp"

class Grass : public Plant {
	public:
		Grass(Universe&, int x, int y, int t_lahir);
		void grow() const;
		int power() const;
		float tgrow() const ;
		char ch() const ;
		int umur() const;
		void update_grow() ;
		void interact(Organism*);
};
#endif
