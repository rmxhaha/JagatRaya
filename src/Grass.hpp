#ifndef GRASS_H
#define GRASS_H
#include "IsA.hpp"
#include "Plant.hpp"

class Grass : public Plant {
	public:
		Grass(Universe&, int x, int y,float currentAge);
		void grow() const;
		int power() const;
		float tgrow() const ;
		char ch() const ;
		int age() const;
		void update_grow() ;
		void interact(Organism*);
};
#endif
