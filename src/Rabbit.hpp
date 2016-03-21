#include "Herbivore.hpp"
#ifndef _RABBIT_H
#define _RABBIT_H
class Rabbit: public Herbivore {
    public:
        Rabbit(Universe& u,int x,int y,float currentAge);
        void update_logic();
        char ch() const;
        float speed() const;
        int power() const;
        int age() const;
        void interact(Organism*);
       // void triggerRace(Race*);
};
#endif // _RABBIT_H
