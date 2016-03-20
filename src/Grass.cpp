#include "Grass.hpp"

Grass::Grass(Universe& b, int x, int y,float currentAge):Plant(b,x,y,currentAge) {
	 universe->board.SetEl(ch(),x,y);
}

int Grass::power()const{return 10;}
float Grass::tgrow()const{return 2;}
char Grass::ch()const{return 'G';}
<<<<<<< HEAD
int Grass::umur() const {return 40;}
=======
int Grass::age() const {return 40;}

>>>>>>> 35503fc53455a59eab8c64bb50a3d0df40d6ee36
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
