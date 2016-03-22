#include "Herbivore.hpp"
#include "Race.hpp"
#include "RaceState.hpp"
#include "IsA.hpp"
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
        void triggerRace(Race*);
    private:
        Race* Ra;
};
#endif // _RABBIT_H
