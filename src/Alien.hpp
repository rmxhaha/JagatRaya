#include "Carnivore.hpp"

#ifndef ALIEN_H
#define ALIEN_H

/**
 * Alien class.
 * Alien will kill everything in it's way. Alien have the highest speed.
 */
class Alien:public Carnivore{
	public:
	/** \brief Alien Constructor
     *
     * \param universe Universe it belong in
     * \return Alien
     *
     */
	Alien(Universe& u,int x, int y,float currentAge);
	/** \brief see Animal::update_logic
	*/
	void update_logic();
	/** find will find the nearest organism from the alien
	*/
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
