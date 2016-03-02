#include "Grass.hpp"

Grass::Grass(Universe& b, int x, int y, int t_lahir):Plant(b,x,y,t_lahir) {}

int Grass::power(){return 10;}
float Grass::tgrow(){return 6;}
char Grass::ch(){return 'G';}