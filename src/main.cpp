#define TESTING_STATE FALSE
#define USE_THREAD TRUE

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
#include "OrganismFactory.hpp"

#if TESTING_STATE
#include "gtest/gtest.h"
#endif // TESTING_STATE

#include <iostream>
#include <fstream>
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
	OrganismFactory organismFactory(u);
	organismFactory.CreateDeer(5, 4);
	organismFactory.CreateDeer(2, 2);
	organismFactory.CreateTiger(8, 7);
	Sleep(100);
	while(true){
		if(GetAsyncKeyState(VK_ESCAPE)){
			break;
		}
		else if(GetAsyncKeyState(VK_SPACE)){
            // Save Board to out.txt
            ofstream out("out.txt");
            streambuf *coutbuf = cout.rdbuf(); //save old buf
            cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
            u.board.PrintBoard();
            cout.rdbuf(coutbuf);

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
			organismFactory.CreateRandom();
		}
	    u.update(100);
		u.board.PrintBoard();
	    Sleep(200*sleep_multiplier);
	}
    return 0;
}

