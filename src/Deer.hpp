#ifndef DEER_H
#define DEER_H

#include "Herbivore.hpp"
#include "IsA.hpp"
/**
 * Deer class.
 * Deer can eat plants.
 * Deer can avoid tiger if tiger is near. Deer will look for other deer if tiger is far.
 */
class Deer:public Herbivore{
	public:
	/** \brief Deer Constructor
     *
     * \param universe Universe it belong in
     * \return Deer
     *
     */
	Deer(Universe& u,int x,int y,float currentAge);
protected:
	/** \brief see Animal::update_logic
	*/ 
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
#endif // DEER_H
