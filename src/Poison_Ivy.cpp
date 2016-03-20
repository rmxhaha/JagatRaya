#include "Poison_Ivy.hpp"

Poison_Ivy::Poison_Ivy(Universe& b, int x, int y,float currentAge):Plant(b,x,y,currentAge) {}

int Poison_Ivy::power()const{return 13;}
float Poison_Ivy::tgrow()const{return 8;}
char Poison_Ivy::ch()const{return 'P';}
<<<<<<< HEAD
=======
int Poison_Ivy::age() const {return 40;}
>>>>>>> 35503fc53455a59eab8c64bb50a3d0df40d6ee36
void Poison_Ivy::grow() const {
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
	Poison_Ivy NewP(*universe,nj,ni,0);
}

void Poison_Ivy::interact(Organism*){}

void Poison_Ivy::update_grow()
{
	grow();
}
int Poison_Ivy::umur() const {return 40;}