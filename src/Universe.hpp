#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <functional>
#include <vector>
#include <map>

#include "board.hpp"
#include "Organism.hpp"

using namespace std;



class Organism;
class Universe {
public:
    /** \brief Universe Constructor
     *
     * \param w int width of map
     * \param h int height of map
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

    Board board; // expose ?
protected:
    int maxOrganismPerCell;
    Universe();


};

#endif // UNIVERSE_H
