#include "Carnivore.hpp"

#ifndef EAGLE_H
#define EAGLE_H

class Eagle : public Carnivore {
	public:
	Eagle(Universe& u,int x, int y,float currentAge);
	void update_logic();
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
;
#endif
