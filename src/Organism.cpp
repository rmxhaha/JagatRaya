#include "Organism.hpp"


Organism::Organism(Universe& u, int _x, int _y,  float currentAge) : universe(&u), x(_x), y(_y), is_dead(false), cAge(currentAge) {
}

int Organism::getX() const { return x; }
int Organism::getY() const { return y; }
float Organism::getCurrentAge() const { return cAge; }

void Organism::setX( int _x ){
    x = _x;
}
void Organism::setY( int _y ){
    y = _y;
}
void Organism::setCurrentAge( float age ) {
    cAge = age;
}

bool Organism::isDead() const { return is_dead; }
bool Organism::isAlive() const { return !is_dead; }

void Organism::forceKill(){
    is_dead = true;
    universe->board.DelEl(ch(),y,x);
}

void Organism::update(float dt){
    cAge += dt;

    if( cAge > age() )
        forceKill();
}
