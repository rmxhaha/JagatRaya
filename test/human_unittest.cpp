#include "human_unittest.hpp"
#include "../src/UniverseSTL.hpp"
#include <cassert>
#include <iostream>

void Test::HumanTest::HumanCharTest(){
    Board b(10,10);
    UniverseSTL u(b,1);
    Human h(u,0,0,0);
    u.add(&h);
    assert( h.ch() == 'H' );
    std::cout << "HumanCharTest Pass";
}

