#include "universe.hpp"
#include <algorithm>
#include <stdexcept>

using namespace std;

Universe::Universe(int w, int h, int m=1) : board(w,h), MaxOrganismPerCell(m){
    if( MaxOrganismPerCell < 1 ) throw range_error("MaxOrganismPerCell must be more than 0");
Universe::Universe(){
}
Universe::~Universe(){
}
