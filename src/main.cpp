#include "IsA.hpp"
#include "Universe.hpp"
#include "Human.hpp"
#include "windows.h"
#include "Tiger.hpp"
#include "Grass.hpp"
#include "Poison_Ivy.hpp"
#include <iostream>
using namespace std;

int main(){
	Universe u(20,20);
	Human* h = new Human(u,0,0,10);
	Tiger* t = new Tiger(u,0,1,9);
	Grass* g = new Grass(u,5,5,12);
	Poison_Ivy* p= new Poison_Ivy(u,2,3,11);
    u.add(h);
    u.add(t);
	u.add(g);
	u.add(p);
    while(true){
        u.board.PrintBoard();
        u.update(100);
        Sleep(200);
    }
    return 0;
}

