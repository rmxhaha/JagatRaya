#include "universe.hpp"
#include <algorithm>
#include <stdexcept>

using namespace std;

Universe::Universe(Board b, int m){
    board = b;
    maxOrganismPerCell = m;
    if( maxOrganismPerCell < 1 ) throw range_error("MaxOrganismPerCell must be more than 0");
}

Universe::~Universe(){
}

