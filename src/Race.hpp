#ifndef _RACE_H
#define _RACE_H
#include "RaceState.hpp"
#include "Organism.hpp"
class Organism;
class Race{
 public:
    Race(int SX,int SY,int EX,int EY);
     int getStartX();
     int getStartY();
     int getFinishX();
     int getFinishY();
     RaceState getState();
     bool joinRabbit(Organism*);
     bool joinTurtle(Organism*);

 private:
    int startX;
    int startY;
    int endX;
    int endY;
    RaceState state;
    Organism *Rabbit;
    Organism *Turtle;
};

#endif // _RACE_H
