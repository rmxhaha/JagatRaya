#include "Organism.hpp"

#ifndef PLANT_H
#define PLANT_H

class Plant : public Organism {
public:
	Plant(Board& b, int x, int y, int t_lahir);
protected:
	void grow();
	virtual float tgrow() const = 0;
};


#endif
