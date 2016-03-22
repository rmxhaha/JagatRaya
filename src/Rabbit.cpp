#include "Rabbit.hpp"
#include "Grass.hpp"
Rabbit::Rabbit(Universe& u, int x, int y,float currentAge):Herbivore(u,x,y,currentAge){
    universe->board.SetEl(ch(),x,y);
}

void Rabbit::update_logic(){
	//Update Tiger move
	move(goRandom());
}
char Rabbit::ch() const {
	return 'R';
}
float Rabbit::speed() const {
	return 7;
}
int Rabbit::power() const {
	return 3;
}
int Rabbit::age() const {
	return 60;
}

void Rabbit::interact(Organism* O){
    if(isA<Grass,Organism>(O)){
		O->forceKill();
	}
}

void Rabbit::triggerRace(Race *_Ra)
{
    if(_Ra->getState()==RaceState::RECRUITMENT)
    {
        if(_Ra->joinRabbit(this))
        {
          Ra = new Race (_Ra->getStartX(),_Ra->getStartY(),_Ra->getFinishX(),_Ra->getFinishY());
        }
    }
}
