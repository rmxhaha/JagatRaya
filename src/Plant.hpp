#include "Organism.hpp"
#include "Universe.hpp"

#ifndef PLANT_H
#define PLANT_H

class Plant : public Organism {
public:
	Plant(Universe& u, int x, int y,float currentAge);
	void update(float dt);
protected:
	virtual void update_grow();
	virtual void grow() const =0;
	virtual float tgrow() const = 0;
	float timebuffer;
};


#endif
