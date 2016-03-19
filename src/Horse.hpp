#include "Herbivore.hpp"

#ifndef HORSE_H
#define HORSE_H

class Horse:public Herbivore{
	public:
	Horse(Universe& u,int x,int y,int t_lahir);
protected:
	void update_logic();
	char ch() const;
	float speed() const;
	int power() const;
	int umur() const;
	void interact(Organism*);
};
#endif
