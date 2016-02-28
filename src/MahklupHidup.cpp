#include "MahklupHidup.hpp"


MahklupHidup::MahklupHidup(Board& b, int _x, int _y, int _tlahir) : board(b), x(_x), y(_y), tlahir(_tlahir), is_dead(false) {
}

bool MahklupHidup::isDead() const { return is_dead; }
bool MahklupHidup::isAlive() const { return !is_dead; }

void MahklupHidup::forceKill(){ is_dead = true; }

