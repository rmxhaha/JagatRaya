#include "UniverseList.hpp"
#include "board.hpp"
#include <cstdio>
#include <stdexcept>
#if USE_THREAD
#include <thread>
#endif // USE_THREAD

UniverseList::UniverseList(Board b, int m) : Universe(b, m){

}

UniverseList::~UniverseList()
{
    //dtorchrono::milliseconds(200)
}

#if USE_THREAD
#include <chrono>
#endif // USE_THREAD

void UniverseList::add(Organism* m){
    MList.push_back(m);
    killWeakestOrganismAt(m -> getX(), m -> getY());
    #if USE_THREAD
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
    #endif // USE_THREAD
}

void UniverseList::notifyMovement(Organism* o){
    #if USE_THREAD
    mu.lock();
    #endif // USE_THREAD
    killWeakestOrganismAt(o -> getX(), o -> getY());
    OrganismList pool;
    for( auto its = MList.begin(); its != MList.end(); its = its->next ){
        Organism* it = its->val;
        if( o->getX() == it->getX() && o->getY() == it->getY() ){
            pool.push_back(it);
        }
    }

    for( auto its = pool.begin(); its != pool.end(); its = its -> next ) {
        Organism* it = its -> val;
        if( it == o ) continue;
        it->interact(o);
        if( o->isAlive() )
            o->interact(it);
    }
    #if USE_THREAD
    mu.unlock();
    #endif // USE_THREAD
}

void UniverseList::killWeakestOrganismAt(int x, int y) {
    OrganismList pool;
    for( auto its = MList.begin(); its != MList.end(); its = its->next ){
        Organism* it = its->val;
        if( x == it->getX() && y == it->getY() ){
            pool.push_back(it);
        }
    }


    // 1 for himself not counted
    if( pool.size() > maxOrganismPerCell ){
        // kill the weakest regardless of interaction
        Organism* weakest = (*pool.begin()).val;
        for( auto its = pool.begin()->next; its != pool.end(); its = its -> next )
        {
            Organism* it = (*its).val;
            if( it -> power() < weakest->power() ){
                weakest = it;
            }
        }
        weakest->forceKill();
    }
}

void UniverseList::update( float dt ){
    int count = 0;
    for( auto its = MList.begin(); its != MList.end(); its = its->next) {
        Organism* it = its->val;
        if( it->isAlive() ){
            it->update(dt);
            ++ count;
        }
    }
    printf("%d", count);
}
void UniverseList::cleanCronJob() {
    while (!MList.begin()->val -> isAlive()) {
        MList.pop_front();
    }
    for( auto its = MList.begin(); its != MList.end(); its = its->next) {
        if (its -> next != MList.end())
        {
            Organism* it = its -> next ->val;
            if( !it->isAlive() ){
                its -> next = its -> next ->next;
            }
        }

    }
}


void UniverseList::notifyRace(int sx, int sy, int ex, int ey){
    // init race here

}
#if USE_THREAD
void UniverseList::tearDown(){
    for( auto its = MList.begin(); its != MList.end(); its = its->next) {
        Organism* it = its ->val;
        it -> forceKill();
    }
    for (int i = 0; i < vt.size(); ++i) {
        vt[i].join();
    }
}
#endif // USE_THREAD
