#define TESTING_STATE FALSE

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

#if TESTING_STATE
#include "gtest/gtest.h"
#endif // TESTING_STATE

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    #if TESTING_STATE
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    #endif // TESTING_STATE

	int sleep_multiplier = 1;
    srand(444);
    Board b(10,10);
	UniverseList u(b,2);
	Deer *d = new Deer(u,5,4,10);
	Deer *d2 = new Deer(u,2,2,10);
	Tiger* t = new Tiger(u,8,7,10);
	u.add(d);
	u.add(d2);
	u.add(t);
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
	    Sleep(200*sleep_multiplier);
	}
    return 0;
}

