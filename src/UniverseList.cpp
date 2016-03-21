#include "UniverseList.hpp"
#include "board.hpp"
#include <cstdio>
#include <stdexcept>
UniverseList::UniverseList(Board b, int m){
    board = b;
    maxOrganismPerCell = m;
    if( maxOrganismPerCell < 1 ) throw range_error("MaxOrganismPerCell must be more than 0");
}

UniverseList::~UniverseList()
{
    //dtor
}

void UniverseList::add(Organism* m){
    MList.push_back(m);
}

void UniverseList::notifyMovement(Organism* o){
    OrganismList pool;
    for( auto its = MList.begin(); its != MList.end(); its = its->next ){
        Organism* it = its->val;
        if( o->getX() == it->getX() && o->getY() == it->getY() ){
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

    for( auto its = pool.begin(); its != pool.end(); its = its -> next ) {
        Organism* it = its -> val;
        if( it == o ) continue;
        it->interact(o);
        o->interact(it);
    }
}

void UniverseList::update( float dt ){
    printf("%d", MList.size());
    for( auto its = MList.begin(); its != MList.end(); its = its->next) {
        Organism* it = its->val;
        if( it->isAlive() )
            it->update(dt);
    }
}
