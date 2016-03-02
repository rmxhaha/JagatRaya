#include <functional>
#include <vector>
#include <map>

#include "board.hpp"
#include "Organism.hpp"

using namespace std;


class Organism;
class Universe {
public:
    enum class Event {
        MOVEMENT
    };

    typedef function<void (Organism*)> CallbackFunction;

    Universe(int w, int h);
    ~Universe();

    void add(Organism* m);
    void listen(Event evt, CallbackFunction callback);
private:
    void publish(Event evt, Organism* x);
    void interact(Organism* m);

    vector<Organism*> MList;
    map<Event, vector<CallbackFunction>> subscriber;
    Board board;
};
