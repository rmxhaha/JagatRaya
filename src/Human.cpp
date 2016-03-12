#include "Human.hpp"
#include "IsA.hpp"

Human::Human(Universe& universe, int x, int y,float currentAge) : Carnivore(universe,x,y,currentAge) {
    universe.board.SetEl(ch(),x,y);
}

void Human::update_logic(){
    move(goRandom());
}
char Human::ch() const { return 'H'; }

int Human::power() const{ return 1; }
int Human::age() const { return 5000; }
float Human::speed() const { return 3; }
void Human::interact(Organism* o){
    if( isA<Human>(o)){
        copulate();
    }
}

void Human::copulate(){
    Human *h = new Human(*universe,getX(), getY(),0);
    universe->add(h);
}
