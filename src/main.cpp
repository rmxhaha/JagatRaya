#include "IsA.hpp"
#include "Universe.hpp"
#include "Human.hpp"
#include "windows.h"
#include "Tiger.hpp"

#include "../Test/board_unittest.hpp"


#include <iostream>
using namespace std;

void test(){
    Test::BoardTest::DimensionTest();
}

int main()
{
    test();
    return 0;

	Universe u(10,10);
	Human* h = new Human(u,0,0,10);
	Tiger* t = new Tiger(u,0,1,10);

    u.add(h);
    u.add(t);

    while(true){
        u.board.PrintBoard();
        u.update(100);
        Sleep(100);
    }
    return 0;
}

