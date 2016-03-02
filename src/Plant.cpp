#include "Plant.hpp"
#include <ctime>

Plant::Plant(Universe& b, int x, int y, int t_lahir):Organism(b,x,y,t_lahir){}

void Plant::grow(){
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
<<<<<<< HEAD
	int nt=tlahir+tgrow;
	Plant newP(board,nj,ni,nt);
=======
	int nt=tlahir+tgrow();
//	Plant NewP(universe,nj,ni,nt);
>>>>>>> f1d561af023cb39d83276e0aeb15fdefcb793892
}
