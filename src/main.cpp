#include "IsA.hpp"
#include "UniverseList.hpp"
#include "Human.hpp"
#include "windows.h"
#include "Eagle.hpp"
#include "Alien.hpp"
#include "Tiger.hpp"
#include "Grass.hpp"
#include "Deer.hpp"
#include "Poison_Ivy.hpp"


#include <iostream>
using namespace std;

int main()
{
    srand(444);
    Board b(10,10);
	UniverseList u(b,2);
	Sleep(100);
	while(true){
		if(GetAsyncKeyState(VK_ESCAPE)){
			break;
		}
		else if(GetAsyncKeyState(VK_SPACE)){
            Sleep(100);
			while(true){
				if(GetAsyncKeyState(VK_SPACE)){
					break;
				}
				else if(GetAsyncKeyState(0x4E)){
				//press N to continue
					u.update(100);
					u.board.PrintBoard();
				    Sleep(200);
				}
                Sleep(1);
			}
		}
		else if(GetAsyncKeyState(0x41)){
		//press A to spawn
			Sleep(100);
			int i = rand() % 7 + 1;
			int xx = rand() % 10;
			int yy = rand() % 10;
			Organism* ox;
			switch (i){
				case 1 :
					ox = new Deer(u,xx,yy,10);
					break;
				case 2 :
					ox = new Alien(u,xx,yy,10);
					break;
				case 3 :
					ox = new Eagle(u,xx,yy,10);
					break;
				case 4 :
					ox = new Grass(u,xx,yy,10);
					break;
				case 5 :
					ox = new Human(u,xx,yy,10);
					break;
				case 6 :
					ox = new Poison_Ivy(u,xx,yy,10);
					break;
				case 7 :
					ox = new Tiger(u,xx,yy,10);
					break;
				default :
					break;
			}
			u.add(ox);
		}
	    u.update(100);
		u.board.PrintBoard();
	    Sleep(200);
	}
    return 0;
}

