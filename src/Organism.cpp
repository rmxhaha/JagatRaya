#include "Organism.hpp"


Organism::Organism(Universe& u, int _x, int _y,  float currentAge) : universe(&u), x(_x), y(_y), is_dead(false), cAge(currentAge) {
}

int Organism::getX() { return x; }
int Organism::getY() { return y; }
void Organism::setX(int x) { this -> x = x; }
void Organism::setY(int y) { this -> y = y; }
void Organism::setXY(int x, int y) { this -> x = x, this -> y = y; }

bool Organism::isDead() const { return is_dead; }
bool Organism::isAlive() const { return !is_dead; }

void Organism::forceKill(){
    is_dead = true;
    universe->board.DelEl(ch(),x,y);
}

void Organism::update(float dt){
    cAge += dt;

    if( cAge > age() )
        forceKill();
}
