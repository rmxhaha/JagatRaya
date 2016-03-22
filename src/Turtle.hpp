#include "Herbivore.hpp"
#include "IsA.hpp"
#ifndef _TURTLE_H
#define _TURTLE_H

class Turtle:public Herbivore{
    public:
    	Turtle(Universe& u,int x,int y,float currentAge);
        void update_logic();
        char ch() const;
        float speed() const;
        int power() const;
        int age() const;
        void interact(Organism*);
       // void triggerRace(Race*);

};
#endif // _TURTLE_H
