#include "OrganismFactory.hpp"
#include "Deer.hpp"
#include "Alien.hpp"
#include "Eagle.hpp"
#include "Grass.hpp"
#include "Human.hpp"
#include "Rabbit.hpp"
#include "Turtle.hpp"
#include "Poison_Ivy.hpp"
#include "Tiger.hpp"

OrganismFactory::OrganismFactory(Universe& _u, float _currentAge) {
	u = &_u;
	currentAge = _currentAge;
}

void OrganismFactory::SetCurrentAge(float _currentAge) {
	currentAge = _currentAge;
}

Organism* OrganismFactory::CreateRandom() {
	int x = rand() % u -> board.GetH();
	int y = rand() % u -> board.GetW();
	return CreateRandomAt(x, y);
}

Organism* OrganismFactory::CreateRandomAt(int x, int y) {
	int i = rand() % 7 + 1;
	Organism* ox;
	switch (i){
		case 1 :
			ox = new Deer(*u,x,y,currentAge);
			break;
		case 2 :
			ox = new Alien(*u,x,y,currentAge);
			break;
		case 3 :
			ox = new Eagle(*u,x,y,currentAge);
			break;
		case 4 :
			ox = new Grass(*u,x,y,currentAge);
			break;
		case 5 :
			ox = new Human(*u,x,y,currentAge);
			break;
        case 6 :
			ox = new Poison_Ivy(*u,x,y,currentAge);
			break;
		case 7 :
			ox = new Tiger(*u,x,y,currentAge);
			break;
		default :
			break;
	}
	u -> add(ox);
	return ox;
}

Organism* OrganismFactory::CreateDeer(int x,int y) {
	Organism* ox;
	ox = new Deer(*u,x,y,currentAge);
	u -> add(ox);
	return ox;
}
Organism* OrganismFactory::CreateTiger(int x,int y) {
	Organism* ox;
	ox = new Tiger(*u,x,y,currentAge);
	u -> add(ox);
	return ox;
}
Organism* OrganismFactory::CreateAlien(int x,int y) {
	Organism* ox;
	ox = new Alien(*u,x,y,currentAge);
	u -> add(ox);
	return ox;
}
Organism* OrganismFactory::CreateEagle(int x,int y) {
	Organism* ox;
	ox = new Eagle(*u,x,y,currentAge);
	u -> add(ox);
	return ox;
}
Organism* OrganismFactory::CreateGrass(int x,int y) {
	Organism* ox;
	ox = new Grass(*u,x,y,currentAge);
	u -> add(ox);
	return ox;
}
Organism* OrganismFactory::CreateHuman(int x,int y) {
	Organism* ox;
	ox = new Human(*u,x,y,currentAge);
	u -> add(ox);
	return ox;
}
Organism* OrganismFactory::CreatePoisonIvy(int x,int y) {
	Organism* ox;
	ox = new Poison_Ivy(*u,x,y,currentAge);
	u -> add(ox);
	return ox;
}
Organism* OrganismFactory::CreateTurtle(int x,int y) {
	Organism* ox;
	ox = new Turtle(*u,x,y,currentAge);
	u -> add(ox);
	return ox;
}
Organism* OrganismFactory::CreateRabbit(int x,int y) {
	Organism* ox;
	ox = new Rabbit(*u,x,y,currentAge);
	u -> add(ox);
	return ox;
}
