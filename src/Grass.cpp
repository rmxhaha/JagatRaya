#include "Grass.hpp"

Grass::Grass(Universe& b, int x, int y, int t_lahir):Plant(b,x,y,t_lahir) {
	 universe.board.SetEl(ch(),x,y);
}

int Grass::power()const{return 10;}
float Grass::tgrow()const{return 2;}
char Grass::ch()const{return 'G';}
int Grass::umur() const {return 40;}
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
	int nt=tlahir+tgrow();
	Grass NewG(universe,nj,ni,nt);
}

void Grass::update_grow()
{
	grow();
}