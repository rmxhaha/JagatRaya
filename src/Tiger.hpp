#include "Carnivore.hpp"
#include "IsA.hpp"

#ifndef TIGER_H
#define TIGER_H
/**
 * Tiger class.
 * Tiger will chase deer and horse.
 * Tiger can eat deer and horse.
 */
 
class Tiger:public Carnivore{
	public:
	/** \brief Tiger Constructor
	 *
	 * \param universe Universe it belong in
	 * \return Tiger
	 *
	 */
	Tiger(Universe& u,int x,int y,float currentAge);
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
#endif // TIGER_H
