#include "Organism.hpp"


Organism::Organism(Universe& u, int _x, int _y, int _tlahir) : universe(&u), x(_x), y(_y), tlahir(_tlahir), is_dead(false) {
}

int Organism::getTLahir() { return tlahir; }
int Organism::getX() { return x; }
int Organism::getY() { return y; }

bool Organism::isDead() const { return is_dead; }
bool Organism::isAlive() const { return !is_dead; }

void Organism::forceKill(){
    is_dead = true;
    universe->board.DelEl(ch(),x,y);
}

