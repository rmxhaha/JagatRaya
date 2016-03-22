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
#include "Race.hpp"
using namespace std;



class Organism;
class Universe {
public:
    /** \brief Universe Constructor
     *  \param board board of the Universe simulation
     *  \param m maximum number of Organism per cell
     */
    Universe(Board board,int m);

    /** \brief Universe Destructor
     *
     */
    ~Universe();

    /** \brief add new organism to this Universe
     *
     * \param m Organism* organism inside Universe
     * \return void
     *
     */
    virtual void add(Organism* m) = 0;
    /** \brief notifyUniverse of a movement so Universe may notify to all organism where this notification is relevant
     *
     *  \param x the organism who moved
     *  \return
     */
    virtual void notifyMovement(Organism* x) = 0;

    /** \brief Update all Organism inside the universe
     *
     *  \param dt delta time from previous update
     *  \return void
     */
    virtual void update(float dt) = 0;

    /** \brief kill the weakest organism in x,y coordinate if that cell exceed N limits per cell
     *
     *  \param x coordinate
     *  \param y coordinate
     *  \return void
     */
    virtual void killWeakestOrganismAt(int x, int y) = 0;
    /** \brief notify all Rabbit and Turtle when a race is announced
     *
     *  \param sx starting coordinate
     *  \param sy starting coordinate
     *  \param ex finish coordinate
     *  \param ey finish coordinate
     *  \return void
     */
    virtual void notifyRace(int sx, int sy, int ex, int ey) = 0;
    /** \brief clean death animal that is still inside the Universe. This function is called periodically
     *
     *  \return void
     */

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
