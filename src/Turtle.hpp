#include "Herbivore.hpp"
#ifndef _TURTLE_H
#define _TURTLE_H

class Turtle:public Herbivore{
    public:
    	Turtle(Universe& u,int x,int y,float currentAge);
    protected:
        void update_logic();
        char ch() const;
        float speed() const;
        int power() const;
        int umur() const;
        void interact(Organism*);

};
#endif // _TURTLE_H
