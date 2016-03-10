#include "Carnivore.hpp"

#ifndef TIGER_H
#define TIGER_H

class Tiger:public Carnivore{
	public:
	Tiger(Universe& u,int x,int y,int t_lahir);
protected:
	void update_logic();
	char ch() const;
	float speed() const;
	int power() const;
	int umur() const;
	void interact(Organism*);
};
#endif
