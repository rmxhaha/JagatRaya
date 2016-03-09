#include "Universe.hpp"
#include <algorithm>

using namespace std;

Universe::Universe(int w, int h) : board(w,h){
}
Universe::~Universe(){
}
void Universe::add(Organism* m){
    MList.push_back(m);
}

void Universe::publish(Event evt, Organism* o){
    for( auto& it : MList ){
        if( it == o ) continue;
        if( o->getX() == it->getX() && o->getY() == it->getY() ){
            it->interact(o);
            o->interact(it);
        }
    }

}

void Universe::update( float dt ){
    for( auto&it: MList ){
        it->update(dt);
    }
}
