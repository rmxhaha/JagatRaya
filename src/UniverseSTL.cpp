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
    killWeakestOrganismAt(m -> getX(), m -> getY());
}

void UniverseSTL::notifyMovement(Organism* o){
    killWeakestOrganismAt(o -> getX(), o -> getY());
    vector<Organism*> pool;
    for( auto& it : MList ){
        if( o->getX() == it->getX() && o->getY() == it->getY() ){
            pool.push_back(it);
        }
    }

    for( auto& it: pool ){
        if( it == o ) continue;
        it->interact(o);
        if( o->isAlive())
            o->interact(it);
    }

}

void UniverseSTL::killWeakestOrganismAt(int x, int y) {
    vector<Organism*> pool;
    for( auto& it : MList ){
        if( x == it->getX() && y == it->getY() ){
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
}

void UniverseSTL::update( float dt ){
    for( auto&it: MList ){
        if( it->isAlive() )
            it->update(dt);
    }
}

void UniverseSTL::triggerRace(int sx, int sy, int ex, int ey){
    // init race here
}
