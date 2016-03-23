#include "Race.hpp"
#include "RaceState.hpp"

Race::Race(int SX,int SY,int EX,int EY)
{
    startX=SX;
    startY=SY;
    endX=EX;
    endY=EY;
    state=RaceState::RECRUITMENT;
    Rabbit=NULL;
    Turtle=NULL;
}

int Race::getStartX(){ return startX;}
int Race::getStartY(){ return startY;}
int Race::getFinishX(){ return endX;}
int Race::getFinishY(){ return endY;}
RaceState Race::getState(){ return state;}
bool Race::joinRabbit(Organism* _R)
{
    if(Rabbit==NULL)
    {
        Rabbit=_R;
        return true;
    }
    else
        return false;
}

bool Race::joinTurtle(Organism* Tu)
{
    if(Turtle==NULL)
    {
        Turtle=Tu;
        return true;
    }
    else
        return false;
}



void Race::updateRace()
{
    if(Rabbit!=NULL&&Turtle!=NULL)
    {
        if(state==RaceState::RECRUITMENT)
        {
            state=RaceState::WAITING_FOR_COMPETITOR;
        }
        if(state==RaceState::WAITING_FOR_COMPETITOR)
        {
            if((Rabbit->getX()==startX&&Rabbit->getY()==startY)&&(Turtle->getX()==startX&&Turtle->getY()==startY))
            state=RaceState::RACING;
        }
        if(state==RaceState::RACING)
        {
            if((Rabbit->getX()==endX&&Rabbit->getY()==endY)&&(Turtle->getX()==endX&&Turtle->getY()==endY))
            state=RaceState::RACE_END;
        }

    }

}
