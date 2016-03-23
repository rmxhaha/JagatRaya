#include "Turtle.hpp"
#include "Grass.hpp"


Turtle::Turtle(Universe& u, int x, int y,float currentAge):Herbivore(u,x,y,currentAge){
    universe->board.SetEl(ch(),x,y);
    Ra=NULL;
}

void Turtle::update_logic(){
	//Update Tiger move
	if(Ra==NULL)
    {
	  move(goRandom());
    }
    else
    {
        if(Ra->getState()==RaceState::WAITING_FOR_COMPETITOR)
        {
           move(goTo(Ra->getStartX(),Ra->getStartY()));
        }
    else
        if(Ra->getState()==RaceState::RACING)
        {
            move(goTo(Ra->getFinishX(),Ra->getFinishY()));
        }
    else
        if(Ra->getState()==RaceState::RACE_END)
        {
            Ra=NULL;
        }
    }
}
char Turtle::ch() const {
	return 'U';
}
float Turtle::speed() const {
	return 2;
}
int Turtle::power() const {
	return 3;
}
int Turtle::age() const {
	return 100000;
}

void Turtle::interact(Organism* O){
    if(isA<Grass,Organism>(O)){
		O->forceKill();
	}
}

void Turtle::triggerRace(Race *_Ra)
{
    if(Ra==NULL)
    {
        if(_Ra->joinTurtle(this))
        {
          Ra = _Ra;

        }
    }
}
