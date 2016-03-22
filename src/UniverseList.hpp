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
        void killWeakestOrganismAt(int x, int y);
        void triggerRace(int sx, int sy, int ex, int ey);
        void notifyRace(int sx, int sy, int ex, int ey);
        void cleanCronJob();
        #if USE_THREAD
        void tearDown();
        #endif // USE_THREAD
    private:
        OrganismList MList;
        //std::list<Race*> race;
};

#endif // UNIVERSELIST_H
