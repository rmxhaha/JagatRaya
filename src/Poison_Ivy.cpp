#include "Poison_Ivy.hpp"
#include "Herbivore.hpp"
Poison_Ivy::Poison_Ivy(Universe& b, int x, int y,float currentAge):Plant(b,x,y,currentAge) {
    universe->board.SetEl(ch(),y,x);
}


int Poison_Ivy::power()const{return 13;}
float Poison_Ivy::tgrow()const{return 0.5;}
char Poison_Ivy::ch()const{return 'P';}
int Poison_Ivy::age() const {return 30000;}
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
	 if( (nj < universe->board.GetW()&&nj >=0)&& (ni < universe->board.GetH()&& ni >= 0 ) )
    {
        Poison_Ivy* P=new Poison_Ivy(*universe,nj,ni,0);
	    universe->add(P);
    }

}

void Poison_Ivy::interact(Organism* O){
    if(isA<Herbivore,Organism>(O)){
		O->forceKill();
	}
}

void Poison_Ivy::update_grow()
{
	grow();
}
