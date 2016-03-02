#include "Organism.hpp"
#include "Universe.hpp"

#ifndef PLANT_H
#define PLANT_H

class Plant : public Organism {
public:
	Plant(Universe& u, int x, int y, int t_lahir);
protected:
	void grow();
	virtual float tgrow() const = 0;
};


#endif
