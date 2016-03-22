#ifndef ORGANISM_FACTORY_H
#define ORGANISM_FACTORY_H


#include "Universe.hpp"
#include "Organism.hpp"

class OrganismFactory {
public:
	OrganismFactory(Universe& _u, float = 10);

	void SetCurrentAge(float);

	Organism* CreateRandom();
	Organism* CreateRandomAt(int,int);

	Organism* CreateDeer(int,int);
	Organism* CreateTiger(int,int);
	Organism* CreateAlien(int,int);
	Organism* CreateEagle(int,int);
	Organism* CreateGrass(int,int);
	Organism* CreateHuman(int,int);
	Organism* CreatePoisonIvy(int,int);
private:
	Universe *u;
	float currentAge;
};

#endif
