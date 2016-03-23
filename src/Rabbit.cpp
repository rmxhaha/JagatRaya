#include "Rabbit.hpp"
#include "Grass.hpp"
#include "RaceState.hpp"
Rabbit::Rabbit(Universe& u, int x, int y,float currentAge):Herbivore(u,x,y,currentAge){
    universe->board.SetEl(ch(),x,y);
    Ra=NULL;
}

void Rabbit::update_logic(){
	//Update Tiger move

	if(Ra==NULL)
    {
	  move(goRandom());
    }
    else
    {
        if(Ra->getState()==RaceState::RECRUITMENT)
        {
            move(goRandom());
        }
        else
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
char Rabbit::ch() const {
	return 'R';
}
float Rabbit::speed() const {
	return 5;
}
int Rabbit::power() const {
	return 5;
}
int Rabbit::age() const {
	return 20000;
}

void Rabbit::interact(Organism* O){
    if(isA<Grass,Organism>(O)){
		O->forceKill();
	}
}

void Rabbit::triggerRace(Race *_Ra)
{
    if(Ra==NULL)
    {
        if(_Ra->joinRabbit(this))
        {
          Ra = _Ra;
        }
    }
}
