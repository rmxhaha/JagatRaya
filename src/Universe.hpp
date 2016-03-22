#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <functional>
#include <vector>
#include <map>
#if USE_THREAD
#include <mutex>
#include <thread>
#endif // USE_THREAD


#include "board.hpp"
#include "Organism.hpp"

using namespace std;



class Organism;
class Universe {
public:
    Universe(Board,int);
    /** \brief Universe Constructor
     *
     */

    ~Universe();

    /** \brief
     *
     * \param m Organism* organism inside Universe
     * \return void
     *
     */
    virtual void add(Organism* m) = 0;
    virtual void notifyMovement(Organism* x) = 0;
    virtual void update(float dt) = 0;
    virtual void killWeakestOrganismAt(int x, int y) = 0;
    virtual void notifyRace(int sx, int sy, int ex, int ey) = 0;
    virtual void cleanCronJob() = 0;
    Board board; // expose ?
    #if USE_THREAD
    vector<mutex*> vm;
    #endif // USE_THREAD
protected:
    int maxOrganismPerCell;
    #if USE_THREAD
    mutex mu;
    vector<thread> vt;
    #endif // USE_THREAD


};

#endif // UNIVERSE_H
