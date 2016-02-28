#include "MahklupHidup.hpp"
#include "Direction.hpp"

#ifndef ANIMAL_H
#define ANIMAL_H



class Animal : public MahklupHidup {
public:
	Animal(Board& b, int x, int y, int t_lahir);
	virtual float speed() const = 0;

	void avoid(int x, int y);
	void goTo(int x, int y);
protected:
	void move();
	direction_t direction;

};


#endif
