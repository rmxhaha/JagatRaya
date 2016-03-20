#include "universe.hpp"
#include <algorithm>
#include <stdexcept>

using namespace std;

<<<<<<< HEAD
Universe::Universe(int w, int h, int m=1) : board(w,h), MaxOrganismPerCell(m){
    if( MaxOrganismPerCell < 1 ) throw range_error("MaxOrganismPerCell must be more than 0");
=======
Universe::Universe(){
>>>>>>> 35503fc53455a59eab8c64bb50a3d0df40d6ee36
}
Universe::~Universe(){
}
