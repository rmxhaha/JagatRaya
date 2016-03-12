#ifndef UNIVERSELIST_H
#define UNIVERSELIST_H

#include "Universe.hpp"
#include "OrganismList.hpp"

class UniverseList : public Universe
{
    public:
        UniverseList(Board b, int maxOrganismPerCell);
        ~UniverseList();
        void add(Organism* m);
        void notifyMovement(Organism* x);
        void update(float dt);
    private:
        OrganismList MList;
};

#endif // UNIVERSELIST_H
