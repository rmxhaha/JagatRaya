#include "Organism.hpp"
#include "Direction.hpp"

#ifndef ANIMAL_H
#define ANIMAL_H



class Animal : public Organism {
public:
	Animal(Universe& u, int x, int y, int t_lahir);
	virtual float speed() const = 0;

protected:
	direction_t avoid(int x, int y);
	direction_t goTo(int x, int y);
	void move(direction_t direction);

};


#endif
