#include "Animal.hpp"

#ifndef CARNIVORE_H
#define CARNIVORE_H

class Carnivore :public Animal{
public:
	Carnivore(Board& b, int x, int y, int t_lahir);

};
#endif