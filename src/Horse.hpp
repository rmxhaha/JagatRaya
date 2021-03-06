#include "Herbivore.hpp"
#include "IsA.hpp"
#ifndef HORSE_H
#define HORSE_H
/**
 * Horse class.
 * Horse can eat plants.
 */
class Horse:public Herbivore{
public:
	/** \brief Horse Constructor
	 *
	 * \param universe Universe it belong in
	 * \return Horse
	 *
	 */
	Horse(Universe& u,int x,int y,float currentAge);
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
#endif // HORSE_H
