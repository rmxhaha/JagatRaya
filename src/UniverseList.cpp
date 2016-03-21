#include "UniverseList.hpp"
#include "board.hpp"
#include <cstdio>

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
    killWeakestOrganismAt(m -> getX(), m -> getY());
}

void UniverseList::notifyMovement(Organism* o){
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
