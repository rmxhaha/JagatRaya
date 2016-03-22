#ifndef _RACE_H
#define _RACE_H
#include "RaceState.hpp"
#include "Organism.hpp"
class Organism;
/**
    * Race class.
    * Race is an event class .
    * Race class can manage event race between class Rabbit and class Turtle
    */
class Race{
 public:
    /*
    * Race constructor
    * SX,SY is a starting point where rabbit and turtle begin race
    * EX,EY is a finish point where rabbit and turtle finish the race
    */
    Race(int SX,int SY,int EX,int EY);
    /*
    * return startX
    */
     int getStartX();
    /*
    * return startY
    */
     int getStartY();
    /*
    * return endX
    */
     int getFinishX();
    /*
    * return endY
    */
     int getFinishY();
    /*
    * return  state
    */
     RaceState getState();
    /*
    * return true if rabbit already join race
    */
     bool joinRabbit(Organism*);
    /*
    * return true if turtle already join race
    */
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
