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
    int w,h,N;
    system ("CLS");
    cout << "Input width and height :" <<endl;
    cin >> w>>h;
    system ("CLS");
    cout << "Input maximum organism in one cell :" <<endl;
    cin >> N;
    system ("CLS");
    Board b(w,h);
	UniverseList u(b,N);
	OrganismFactory organismFactory(u);
	organismFactory.CreateEagle(0,0);
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
    int x = rand() % h;
	int y = rand() % w;
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
		else if(GetAsyncKeyState(0x70)){
            Sleep(100);
            organismFactory.CreateAlien(x,y);
		}
        else if(GetAsyncKeyState(0x71)){
            Sleep(100);
            int _x = rand() % h;
	        int _y = rand() % w;
            organismFactory.CreateRabbit(x,y);
            organismFactory.CreateTurtle(_x,_y);
        }
        else if(GetAsyncKeyState(0x72)){
            Sleep(100);
            organismFactory.CreateTiger(x,y);
        }
        else if(GetAsyncKeyState(0x73)){
            Sleep(100);
            organismFactory.CreateDeer(x,y);
        }
        else if(GetAsyncKeyState(0x74)){
            Sleep(100);
            organismFactory.CreateHuman(x,y);
        }
        else if(GetAsyncKeyState(0x75)){
            Sleep(100);
            organismFactory.CreatePoisonIvy(x,y);
        }
        else if(GetAsyncKeyState(0x76)){
            Sleep(100);
            organismFactory.CreateGrass(x,y);
        }
        else if(GetAsyncKeyState(0x77)){
            Sleep(100);
            organismFactory.CreateHorse(x,y);
        }
        else if(GetAsyncKeyState(0x78)){
            Sleep(100);
            organismFactory.CreateEagle(x,y);
        }
		else if(GetAsyncKeyState(0x52)){
        //press  R to addRace
            Sleep(100);
            u.addRace();
		}
		else if(GetAsyncKeyState(0x53)) {
            //press  S to increase speed
            Sleep(100);
            sleep_multiplier++;
		}
		else if(GetAsyncKeyState(0x44)) {
		    //press  D to decrease speed
            Sleep(100);
            sleep_multiplier--;
            if(sleep_multiplier<0)
                sleep_multiplier=0;
		}
		#if USE_THREAD
		#else
            u.update(100);
            u.cleanCronJob();
		#endif // USE_THREAD
             u.board.PrintBoard();
             cout<<endl;


	    Sleep(200/sleep_multiplier);
	}
	u.board.PrintBoard();
	#if USE_THREAD
	finish = true;
	t.join();
	u.tearDown();
	#endif // USE_THREAD
    return 0;
}

