#include "IsA.hpp"
#include "Universe.hpp"
#include "Human.hpp"
#include <iostream>
using namespace std;

int main(){
	Universe u(10,10);
    u.add(new Human(u,0,0,10));
    return 0;
}

