#include "Plant.hpp"
#include "IsA.hpp"
#ifndef POISON_IVY_H
#define POISON_IVY_H

/**
 * Poison_Ivy class.
 * Poison_Ivy can grow or make a new Poison_Ivy object around this object.
 * Anyobject with herbivore class can die if eat Poison_Ivy class
 */

class Poison_Ivy : public Plant {
	public:
    /** \brief Poison_Ivy Constructor
     *
     * \param universe Universe it belong in
     * \return Poison_Ivy
     *
     */
	Poison_Ivy(Universe& b, int x, int y,float currentAge);
     /** \brief see Organism::ch
     */
        char ch() const ;
     /** \brief see Organism::power
     */
		int power() const;
     /** \brief see Organism::age
     */
		int age() const;
     /** \brief see Plant::grow
     */
		void grow() const;
     /** \brief see Plant::tgrow
     */
		float tgrow() const ;
	/** \brief see Plant::update_grow
     */
        void update_grow();
     /** \brief see Organism::interact
     */
		void interact(Organism*);
};
#endif // POISON_IVY_H
