#include "Herbivore.hpp"

#ifndef RABBIT_h
#define RABBIT_h

class Rabbit : public class Herbivore {
	
	public:
		Rabbit(Universe& u,int x,int y,int t_lahir);
	protected:
		void update_logic();
		char ch() const;
		float speed() const;
		int power() const;
		int umur() const;
		void interact(Organism*);
};
#endif