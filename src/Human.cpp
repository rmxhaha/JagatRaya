#include "Human.hpp"


Human::Human(Universe& universe, int x, int y, int t_lahir) : Carnivore(universe,x,y,t_lahir) {
    universe.board.SetEl(ch(),x,y);
}

void Human::update_logic(){
    move(goRandom());
}
char Human::ch() const { return 'H'; }

int Human::power() const{ return 1; }
int Human::age() const { return 5000; }
float Human::speed() const { return 3; }
void Human::interact(Organism*){
}
