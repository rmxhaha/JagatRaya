#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <functional>
#include <vector>
#include <map>
#if USE_THREAD
#include <mutex>
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
    virtual void add(Organism* m) {}
    virtual void notifyMovement(Organism* x) {}
    virtual void update(float dt) {}
    virtual void killWeakestOrganismAt(int x, int y) {}

    Board board; // expose ?
protected:
    int maxOrganismPerCell;
    #if USE_THREAD
    mutex **mu;
    vector<thread*> vt;
    #endif // USE_THREAD


};

#endif // UNIVERSE_H
