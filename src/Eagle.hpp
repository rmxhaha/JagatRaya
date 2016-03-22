#ifndef EAGLE_H
#define EAGLE_H

#include "Carnivore.hpp"
#include "IsA.hpp"
/**
 * Eagle class.
 * Eagle will move around in perimeter.
 */
class Eagle : public Carnivore {
public:
	/** \brief Eagle Constructor
     *
     * \param universe Universe it belong in
     * \return Eagle
     *
     */
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
	/** \brief see Animal::update_logic
	*/
	void update_logic();
};
#endif // EAGLE_H
