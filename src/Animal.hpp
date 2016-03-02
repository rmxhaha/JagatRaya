#include "Organism.hpp"
#include "Direction.hpp"

#ifndef ANIMAL_H
#define ANIMAL_H



class Animal : public Organism {
public:
	Animal(Board& b, int x, int y, int t_lahir);
	virtual float speed() const = 0;

	direction_t avoid(int x, int y);
	direction_t goTo(int x, int y);
protected:
	void move(direction_t direction);

};


#endif
