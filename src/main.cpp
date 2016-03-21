#include "IsA.hpp"
#include "UniverseList.hpp"
#include "Human.hpp"
#include "windows.h"
#include "Eagle.hpp"
#include "Alien.hpp"
#include "Tiger.hpp"
#include "Grass.hpp"
#include "Poison_Ivy.hpp"


#include <iostream>
using namespace std;

int main()
{
    srand(444);
    Board b(10,10);
	UniverseList u(b,2);
	Alien* h = new Alien(u,0,0,10);
	Human* h2 = new Human(u,5,5,10);
	Human* h3 = new Human(u,3,3,10);
	Human* h4 = new Human(u,2,8,10);
	Human* h5 = new Human(u,7,6,10);
	//Tiger* t = new Tiger(u,5,5,10);
	Eagle *e = new Eagle(u,5,4,10);
    u.add(h);
    //u.add(t);
    u.add(h2);
    u.add(h3);
    u.add(h4);
    u.add(h5);
    u.add(e);

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
                Sleep(1);
			}
		}
	    u.update(100);
		u.board.PrintBoard();
	    Sleep(200);
    }
    return 0;
}

