#ifndef HUMAN_H
#define HUMAN_H

#include "Carnivore.hpp"

class Human : public Carnivore {
public:
    Human(Universe& universe, int x, int y,float currentAge);
    virtual char ch() const ;
	virtual int age() const;
	virtual int power() const;
    virtual float speed() const;
    void interact(Organism*);

protected:
    int offspringCount;
    void copulate();
    void update_logic();
    static const int maxOffspring = 2;
};

#endif // HUMAN_H
