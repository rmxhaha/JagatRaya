#include "Herbivore.hpp"

#ifndef TURTLE_h
#define TURTLE_h

class Turtle : public class Herbivore {
	
	public:
		Turtle(Universe& u,int x,int y,int t_lahir);
	protected:
		void update_logic();
		char ch() const;
		float speed() const;
		int power() const;
		int umur() const;
		void interact(Organism*);
};
#endif