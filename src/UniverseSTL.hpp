#ifndef UNIVERSESTL_H
#define UNIVERSESTL_H

#include "Universe.hpp"


class UniverseSTL : public Universe
{
    public:
        UniverseSTL(Board b, int maxOrganismPerCell);
        ~UniverseSTL();
        void add(Organism* m);
        void notifyMovement(Organism* x);
        void update(float dt);
        void killWeakestOrganismAt(int x, int y);
        void triggerRace(int sx, int sy, int ex, int ey);

    private:
        vector<Organism*> MList;
//        vector<Race*> MRace;
};

#endif // UNIVERSESTL_H
