#include "IsA.hpp"
#include "Universe.hpp"
#include "Human.hpp"
#include "windows.h"
#include "Tiger.hpp"
#include "Grass.hpp"
#include "Poison_Ivy.hpp"
#include "../Test/board_unittest.hpp"
#include "../Test/human_unittest.hpp"

#include <iostream>
using namespace std;

void test(){
    Test::BoardTest::DimensionTest();
    Test::HumanTest::HumanCharTest();
}


int main()
{
    srand(444);
	Universe u(10,10,1);
	Human* h = new Human(u,0,0,10);
	Tiger* t = new Tiger(u,5,5,10);
	Grass* g = new Grass(u,3,5,10);
    u.add(h);
    u.add(t);
    u.add(g);
    while(true){
        u.board.PrintBoard();
        u.update(100);
        Sleep(200);
    }
    return 0;
}

