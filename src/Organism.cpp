#include "Organism.hpp"


Organism::Organism(Board& b, int _x, int _y, int _tlahir) : board(b), x(_x), y(_y), tlahir(_tlahir), is_dead(false) {
}

bool Organism::isDead() const { return is_dead; }
bool Organism::isAlive() const { return !is_dead; }

void Organism::forceKill(){ is_dead = true; }

