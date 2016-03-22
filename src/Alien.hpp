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
	/** \brief find the nearest organism from the alien
	 * 	\param prey_x, prey_y Location of the prey
	 * 	\param predator_x,predator_y Location of the alien
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
#endif // ALIEN_H
