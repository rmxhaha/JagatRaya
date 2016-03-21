#include "Herbivore.hpp"

#ifndef HORSE_H
#define HORSE_H

class Horse:public Herbivore{
	public:
	Horse(Universe& u,int x,int y,float currentAge);
protected:
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
};
#endif
