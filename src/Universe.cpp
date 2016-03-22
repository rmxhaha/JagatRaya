#include "universe.hpp"
#include <algorithm>
#include <stdexcept>

using namespace std;

Universe::Universe(Board b, int m){
    board = b;
    maxOrganismPerCell = m;
    if( maxOrganismPerCell < 1 ) throw range_error("MaxOrganismPerCell must be more than 0");
    #if USE_THREAD
    mu = (mutex **)malloc(sizeof(mutex) * b.GetW() * b.GetH());
    #endif // USE_THREAD
}

Universe::~Universe(){
}
