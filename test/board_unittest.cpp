#include "board_unittest.hpp"
#include <cassert>
void Test::BoardTest::DimensionTest(){
    Board b(5,5);
    assert( 5 == b.GetW() );
    assert( 5 == b.GetH() );
    cout << "DimensionTest Pass\n";
}
