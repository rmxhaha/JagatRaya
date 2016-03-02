#include "Human.hpp"


Human::Human(Universe& universe, int x, int y, int t_lahir) : Carnivore(universe,x,y,t_lahir) {
}

void Human::update_logic(){

}

char Human::ch() const { return 'H'; }
int Human::power() const{ return 1; }
int Human::umur() const { return 1; }
float Human::speed() const { return 1; }
