#include "UniverseSTL.hpp"
#include "board.hpp"
#include <stdexcept>
#include <algorithm>
#if USE_THREAD
#include <thread>
#endif // USE_THREAD

using namespace std;
UniverseSTL::UniverseSTL(Board b, int m) : Universe(b, m){
//    MList.reserve(10000);
}

UniverseSTL::~UniverseSTL()
{
    //dtor
}

#if USE_THREAD
#include <chrono>
#endif // USE_THREAD

void UniverseSTL::add(Organism* m){
    MList.push_back(m);
    killWeakestOrganismAt(m -> getX(), m -> getY());

    #if USE_THREAD
    mu.lock();
    killWeakestOrganismAt(m -> getX(), m -> getY());
    mutex* mut = new mutex;
    vm.push_back(mut);
    vt.push_back(thread([&](Organism* m, int vmNumber) {
            while (m -> isAlive()) {
                vm[vmNumber] -> lock();
                m -> update(100);
                this_thread::sleep_for(chrono::milliseconds(200));
                vm[vmNumber] -> unlock();
            }
        }, m, vt.size()));
    mu.unlock();
    #endif // USE_THREAD
}

void UniverseSTL::notifyMovement(Organism* o){
    #if USE_THREAD
    mu.lock();
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
    mu.unlock();
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
    while( pool.size() > maxOrganismPerCell ){
        // kill the weakest regardless of interaction
        auto weakest = pool.begin();
        for( auto it = pool.begin() + 1; it != pool.end(); ++ it )
        {
            if( (*it) -> power() < (*weakest)->power() ){
                weakest = it;
            }
        }
        (*weakest)->forceKill();
        pool.erase(weakest);
    }
}

void UniverseSTL::update( float dt ){
    for( int i = 0; i < MList.size(); ++ i ){
        Organism* it = MList[i];
        if( it->isAlive() ){
            it->update(dt);
        }
    }

}

void UniverseSTL::cleanCronJob() {
    /*
    MList.erase(remove_if(MList.begin(),
        MList.end(),
        [](Organism* x){return !x -> isAlive();}),
    MList.end());
    */
}

void UniverseSTL::notifyRace(int sx, int sy, int ex, int ey){
    // init race here
    Race* Ra = new Race(sx,sy,ex,ey);

}
#if USE_THREAD
void UniverseSTL::tearDown(){
    for( auto&it: MList ){
        it -> forceKill();
    }
    for (int i = 0; i < vt.size(); ++i) {
        vt[i].join();
    }
}
#endif // USE_THREAD
