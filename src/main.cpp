#define TESTING_STATE FALSE

#include "IsA.hpp"
#include "UniverseList.hpp"
#include "UniverseSTL.hpp"
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
    Board b(20,20);
	UniverseSTL u(b,2);
	OrganismFactory organismFactory(u);

	organismFactory.CreateRabbit(1, 9);
	organismFactory.CreateRabbit(6, 9);
    organismFactory.CreateTurtle(3,9);
    organismFactory.CreateTurtle(2,9);
	organismFactory.CreateDeer(10,10);
	organismFactory.CreateTiger(8, 7);
	organismFactory.CreateEagle(0,0);
	u.notifyRace(1,1,19,1);
	u.notifyRace(3,3,19,3);
	Sleep(100);
	#if USE_THREAD
	bool finish = false;
    thread t([&]{
             while (!finish) {
                u.cleanCronJob();
                this_thread::sleep_for(chrono::seconds(1));
             }
             });
    #endif
	while(true){
		if(GetAsyncKeyState(VK_ESCAPE) || u.board.isEmpty()){
			break;
		}
		else if(GetAsyncKeyState(VK_SPACE)){
            #if USE_THREAD
                for (auto it : u.vm) {
                    it -> lock();
                }
            #endif // USE_THREAD
            // Save Board to out.txt
            ofstream out("out.txt");
            streambuf *coutbuf = cout.rdbuf(); //save old buf
            cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!
            u.board.PrintBoard();
            cout.rdbuf(coutbuf);

            Sleep(100);
			while(true){
				if(GetAsyncKeyState(VK_SPACE)){
                    #if USE_THREAD
                        for (auto it : u.vm) {
                            it -> unlock();
                        }
                    #endif // USE_THREAD
					break;
				}
				#if USE_THREAD
				#else
				else if(GetAsyncKeyState(0x4E)){
				//press N to continue
					u.update(100);
					u.board.PrintBoard();
				    Sleep(200);
				}
				#endif // USE_THREAD
                Sleep(1);
			}
		}
		else if(GetAsyncKeyState(0x41)){
		//press A to spawn
			Sleep(100);
			organismFactory.CreateRandom();
		}
		#if USE_THREAD
		#else
            u.update(100);
            u.cleanCronJob();
		#endif // USE_THREAD

		u.board.PrintBoard();

	    Sleep(200*sleep_multiplier);
	}
	u.board.PrintBoard();
	#if USE_THREAD
	finish = true;
	t.join();
	u.tearDown();
	#endif // USE_THREAD
    return 0;
}

