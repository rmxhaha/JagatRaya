#include "Herbivore.hpp"
#ifndef _RABBIT_H
#define _RABBIT_H
class Rabbit: public Herbivore {
    public:
    	Rabbit(Universe& u,int x,int y,float currentAge);
    protected:
        void update_logic();
        char ch() const;
        float speed() const;
        int power() const;
        int umur() const;
        void interact(Organism*);

};
#endif // _RABBIT_H
