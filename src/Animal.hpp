#include "MahklupHidup.hpp"
#include "Direction.hpp"

#ifndef ANIMAL_H
#define ANIMAL_H



class Animal {
public:
	Animal();
	virtual float speed() const = 0;

	void avoid();
	void goTo();
	void move();
protected:
	direction_t direction;
	
};


#endif
