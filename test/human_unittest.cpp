#include "human_unittest.hpp"
#include <cassert>
#include <iostream>

void Test::HumanTest::HumanCharTest(){
    Universe u(10,10);
    Human h(u,0,0,0);
    u.add(&h);
    assert( h.ch() == 'H' );
    std::cout << "HumanCharTest Pass";
}

