#include "IsA.hpp"
#include "Universe.hpp"
#include "Human.hpp"
#include "windows.h"
#include "Tiger.hpp"

#include <iostream>
using namespace std;

int main(){
	Universe u(10,10);
	Human* h = new Human(u,0,0,10);
	Tiger* t = new Tiger(u,0,1,9);

    u.add(h);
    u.add(t);

    while(true){
        u.board.PrintBoard();
        u.update(100);
        Sleep(100);
    }
    return 0;
}

