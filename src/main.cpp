#include "IsA.hpp"
#include "UniverseList.hpp"
#include "Human.hpp"
#include "windows.h"
#include "Eagle.hpp"
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
//	Human* h = new Human(u,0,0,10);
//	Tiger* t = new Tiger(u,5,5,10);
	Eagle *e = new Eagle(u,5,4,10);
 //   u.add(h);
   // u.add(t);
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

