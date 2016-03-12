#include "Organism.hpp"
#include "Direction.hpp"

#ifndef ANIMAL_H
#define ANIMAL_H



class Animal : public Organism {
public:
	Animal(Universe& u, int x, int y,float currentAge);
	virtual float speed() const = 0;

    void update(float dt);
protected:
	direction_t avoid(int x, int y);
	direction_t goTo(int x, int y);
	direction_t goRandom();
	void move(direction_t direction);
    virtual void update_logic();

    float cAge;
    float timebuffer;
};


#endif
