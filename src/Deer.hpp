#include "Herbivore.hpp"

#ifndef DEER_H
#define DEER_H

class Deer:public Herbivore{
	public:
	Deer(Universe& u,int x,int y,int t_lahir);
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
