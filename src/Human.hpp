#ifndef HUMAN_H
#define HUMAN_H

#include "Carnivore.hpp"

class Human : public Carnivore {
public:
    Human(Universe& universe, int x, int y, int t_lahir);
protected:
    void update_logic();
};

#endif // HUMAN_H
