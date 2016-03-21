#include "UniverseSTL.hpp"
#include "board.hpp"
#include <stdexcept>
#if USE_THREAD
#include <thread>
#endif // USE_THREAD

using namespace std;
UniverseSTL::UniverseSTL(Board b, int m) : Universe(b, m){
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
    #if USE_THREAD
    mu[o -> getX()][o -> getY()].lock();
    #endif // USE_THREAD
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
    #if USE_THREAD
    mu[o -> getX()][o -> getY()].unlock();
    #endif // USE_THREAD

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
            #if USE_THREAD
            thread t(it->update, dt);
            #else
            it->update(dt);
            #endif // USE_THREAD
    }
}
