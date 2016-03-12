#include "universe.hpp"
#include <algorithm>

using namespace std;

Universe::Universe(int w, int h, int m) : board(w,h), MaxOrganismPerCell(m){
    if( MaxOrganismPerCell < 1 ) throw range_error("MaxOrganismPerCell must be more than 0");
}
Universe::~Universe(){
}
void Universe::add(Organism* m){
    MList.push_back(m);
}

void Universe::publish(Event evt, Organism* o){
    vector<Organism*> pool;
    for( auto& it : MList ){
        if( o->getX() == it->getX() && o->getY() == it->getY() ){
            pool.push_back(it);
        }
    }

    // 1 for himself not counted
    if( pool.size() > MaxOrganismPerCell ){
        // kill the weakest regardless of interaction
        Organism* weakest = *pool.begin();
        for( auto it = pool.begin() + 1; it != pool.end(); ++ it )
        {
            if( (*it) -> power() < weakest->power() ){
                weakest = *it;
            }
        }
        weakest->forceKill();
    }

    for( auto& it: pool ){
        if( it == o ) continue;
        it->interact(o);
        o->interact(it);
    }

}

void Universe::update( float dt ){
    for( auto&it: MList ){
        if( it->isAlive() )
            it->update(dt);
    }
}
