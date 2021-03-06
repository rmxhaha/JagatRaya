#ifndef UNIVERSESTL_H
#define UNIVERSESTL_H

#include "Universe.hpp"

/**
 * UniverseSTL class.
 * Universe implementation with STL vector as the storage
 */

class UniverseSTL : public Universe
{
    public:
        UniverseSTL(Board b, int maxOrganismPerCell);
        ~UniverseSTL();
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
        vector<Organism*> MList;
        vector<Race*> RList;
//        vector<Race*> MRace;
};

#endif // UNIVERSESTL_H
