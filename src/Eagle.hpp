#include "Carnivore.hpp"
#include "IsA.hpp"
#ifndef EAGLE_H
#define EAGLE_H

class Eagle : public Carnivore {
public:
	Eagle(Universe& u,int x, int y,float currentAge);
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
protected:
	void update_logic();
};
#endif
