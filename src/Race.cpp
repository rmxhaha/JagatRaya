#include "Race.hpp"
#include "RaceState.hpp"

Race::Race(int SX,int SY,int EX,int EY)
{
    startX=SX;
    startY=SY;
    endX=EX;
    endY=EY;
    state=RaceState::RECRUITMENT;

}

int Race::getStartX(){ return startX;}
int Race::getStartY(){ return startY;}
int Race::getFinishX(){ return endX;}
int Race::getFinishY(){ return endY;}
RaceState Race::getState(){ return state;}
