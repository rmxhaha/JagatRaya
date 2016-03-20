#include "Alien.hpp"

Alien::Alien(Universe& u, int x, int y,float currentAge):Carnivore(u,x,y,currentAge){}

void Alien::update(){//Update Alien move
}

char Alien::ch() const{return '@';}
float Alien::speed() const{return 1;}
int Alien::power() const{return 50;}
int Alien::age() const{return 100;}
