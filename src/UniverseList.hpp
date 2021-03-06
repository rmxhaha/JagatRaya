#ifndef UNIVERSELIST_H
#define UNIVERSELIST_H

#include "Universe.hpp"
#include "OrganismList.hpp"
#include "RaceList.hpp"

/**
 * UniverseList class.
 * Universe implementation with List as the storage data structure
 */

class UniverseList : public Universe
{
    public:
        UniverseList(Board b, int maxOrganismPerCell);
        ~UniverseList();
        void add(Organism* m);
        void notifyMovement(Organism* x);
        void update(float dt);
        void killWeakestOrganismAt(int x, int y);
        void addRace();
        void cleanCronJob();
        #if USE_THREAD
        void tearDown();
        #endif // USE_THREAD
    private:
        OrganismList MList;
        RaceList RList;
        //std::list<Race*> race;
};

#endif // UNIVERSELIST_H
