#include "Grass.hpp"

Grass::Grass(Universe& b, int x, int y,float currentAge):Plant(b,x,y,currentAge) {
	 universe->board.SetEl(ch(),x,y);
}

int Grass::power()const{return 10;}
float Grass::tgrow()const{return 2;}
char Grass::ch()const{return 'G';}
int Grass::age() const {return 40;}

void Grass::grow() const {
	bool place=false;
	int ni,nj;
	srand((unsigned)time(NULL));
	while(!place)
	{
		int i1=rand()%3-1;
		int j1=rand()%3-1;
		if(i1!=0||j1!=0)
		{
			ni=y+i1;
			nj=x+j1;
			place=true;
		}
	}
	Grass NewG(*universe,nj,ni,0);
}

void Grass::update_grow()
{
	grow();
}

void Grass::interact(Organism*){}
