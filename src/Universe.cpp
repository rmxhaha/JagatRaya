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


void Universe::listen(Event evt, CallbackFunction callback){
    subscriber[evt].push_back(callback);
}


void Universe::publish(Event evt, Organism* x){
    for( auto& it: subscriber[evt] ){
        it(x);
    }
}

void Universe::interact(Organism* m){
    // eliminate weakest

    // interact
    for( auto& it: MList ){
        //m.interact(it);
    }
}

void Universe::update( float dt ){
    for( auto&it: MList ){
        it->update(dt);
    }
}
