#include "Grass.hpp"

Grass::Grass(Universe& b, int x, int y,float currentAge):Plant(b,x,y,currentAge) {
	 universe->board.SetEl(ch(),y,x);
}

int Grass::power()const{return 2;}
float Grass::tgrow()const{return 0.5;}
char Grass::ch()const{return 'G';}
int Grass::age() const {return 30000;}

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
    if( (nj < universe->board.GetW()&&nj >=0)&& (ni < universe->board.GetH()&& ni >= 0 ) )
    {
	Grass* G=new Grass(*universe,nj,ni,0);
	universe->add(G);
    }

}

void Grass::update_grow()
{
	grow();
}

void Grass::interact(Organism*){}
