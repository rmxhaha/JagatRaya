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
    /** \brief Event types for Observer pattern
    */
    enum class Event {
        MOVEMENT
    };

    typedef function<void (Organism*)> CallbackFunction;

    /** \brief Universe Constructor
     *
     * \param w int width of map
     * \param h int height of map
     *
     */
    Universe(int w, int h);
    ~Universe();

    /** \brief
     *
     * \param m Organism* organism inside Universe
     * \return void
     *
     */
    void add(Organism* m);
    void listen(Event evt, CallbackFunction callback);
    void update(float dt);

    Board board; // expose ?
private:
    void publish(Event evt, Organism* x);
    void interact(Organism* m);

    vector<Organism*> MList;
    map<Event, vector<CallbackFunction>> subscriber;
};

#endif // UNIVERSE_H
