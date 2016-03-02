#include "IsA.hpp"
#include "Universe.hpp"
#include "Human.hpp"
#include "windows.h"

#include <iostream>
using namespace std;

int main(){
	Universe u(10,10);
	Human* h = new Human(u,0,0,10);
    u.add(h);
    while(true){
        u.board.PrintBoard();
        u.update(1);
        Sleep(1000);
    }
    return 0;
}

