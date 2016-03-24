#include "Alien.hpp"

Alien::Alien(Universe& u, int x, int y,float currentAge):Carnivore(u,x,y,currentAge){
    universe->board.SetEl(ch(),y,x);
}

void Alien::update_logic(){//Update Alien move
	int prey_x;
	int prey_y;
	if(!find(prey_x,prey_y,x,y)){
		move(goRandom());
	}
	else{
		move(goTo(prey_x,prey_y));
	}
}

void Alien::interact(Organism * O){
	O->forceKill();
}
char Alien::ch() const{return '@';}
float Alien::speed() const{return 3;}
int Alien::power() const{return 50;}
int Alien::age() const{return 50000;}

class Target {
    public:
	Target(){
    	x = 0;
    	y = 0;
    	distance = 0;
	}
	int x,y,distance;
};

bool Alien::find(int & prey_x,int & prey_y,int predator_x,int predator_y){
	vector<Target> vec;
	Board& board = universe->board;
	int i = 0;
	int j;
	Target T;

	while(i<board.GetH()){
		j=0;
		while(j<board.GetW()){
			if(board.GetEl(i,j).length()>0){
				T.x = i;
				T.y = j;
				T.distance = (predator_x-T.x)*(predator_x-T.x) + (predator_y-T.y)*(predator_y-T.y);
				vec.push_back(T);
			}
			j++;
		}
		i++;
	}
	if(vec.size()>0){
		int min;
		if(vec[0].x!=x && vec[0].y){
			min = vec[0].distance;
			prey_x=vec[0].x;
			prey_y=vec[0].y;
			i=1;
		}
		else{
			min = vec[1].distance;
			prey_x=vec[1].x;
			prey_y=vec[1].y;
			i=2;
		}
		while(i<vec.size()){
			if(vec[i].distance<min && vec[i].x!=x && vec[i].y!=y){
				prey_x=vec[i].x;
				prey_y=vec[i].y;
			}
			i++;
		}
		return true;
	}
	else{
		return false;
	}
}
