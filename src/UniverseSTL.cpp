#include "UniverseSTL.hpp"
#include "board.hpp"
#include <stdexcept>
using namespace std;
UniverseSTL::UniverseSTL(Board b, int m){
    board = b;
    maxOrganismPerCell = m;
    if( maxOrganismPerCell < 1 ) throw range_error("MaxOrganismPerCell must be more than 0");
}

UniverseSTL::~UniverseSTL()
{
    //dtor
}

void UniverseSTL::add(Organism* m){
    MList.push_back(m);
}

void UniverseSTL::notifyMovement(Organism* o){
    vector<Organism*> pool;
    for( auto& it : MList ){
        if( o->getX() == it->getX() && o->getY() == it->getY() ){
            pool.push_back(it);
        }
    }

    // 1 for himself not counted
    if( pool.size() > maxOrganismPerCell ){
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

void UniverseSTL::update( float dt ){
    for( auto&it: MList ){
        if( it->isAlive() )
            it->update(dt);
    }
}
