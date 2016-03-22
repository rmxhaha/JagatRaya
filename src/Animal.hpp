#include "Organism.hpp"
#include "Direction.hpp"

#ifndef ANIMAL_H
#define ANIMAL_H



class Animal : public Organism {
public:
	Animal(Universe& u, int x, int y,float currentAge);
	virtual float speed() const = 0;
    float getTimebuffer() const;

    void update(float dt);
protected:
	direction_t avoid(int x, int y);
	direction_t goTo(int x, int y);
	direction_t goRandom();
	bool findPrey(char prey_ch,int & prey_x,int & prey_y,int predator_x,int predator_y);
	void move(direction_t direction);
    virtual void update_logic();

    float timebuffer;
};


#endif

