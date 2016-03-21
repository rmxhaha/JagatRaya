#include "Carnivore.hpp"

#ifndef ALIEN_H
#define ALIEN_H

/**
 * Alien class.
 * Alien will kill everything in it's way. Alien have the highest speed.
 */
class Alien:public Carnivore{
	public:
	Alien(Universe& u,int x, int y,float currentAge);
	void update_logic();
	bool find(int & prey_x,int & prey_y,int predator_x,int predator_y);
    /** \brief see Organism::ch
     */
    char ch() const ;
    /** \brief see Organism::age
     */
	int age() const;
    /** \brief see Organism::power
     */
	int power() const;
    /** \brief see Animal::speed
     */
    float speed() const;
    /** \brief see Organism::interact
     */
    void interact(Organism*);
};
#endif
