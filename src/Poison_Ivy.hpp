#include "Plant.hpp"
#include "IsA.hpp"
#ifndef POISON_IVY_H
#define POISON_IVY_H
/**
 * Poison Ivy class.
 * Poison Ivy can grow around. If herbivore eat Poison Ivy, the herbivore will die.
 */
class Poison_Ivy : public Plant
{
	public:
	/** \brief Poison_Ivy Constructor
	 *
	 * \param universe Universe it belong in
	 * \return Poison_Ivy
	 *
	 */
	Poison_Ivy(Universe& b, int x, int y,float currentAge);
	protected:
	/** \brief see Organism::power
    */
	int power() const;
	/** \brief see Plant::tgrow
    */
	float tgrow() const;
	/** \brief see Organism::ch
    */
	char ch() const;
	/** \brief see Plant::grow
    */
	void grow()const;
	/** \brief see Organism::age
    */
	int age()const;
	/** \brief see Plant::update_grow
    */
	void update_grow();
	/** \brief see Organism::interact
    */
	void interact(Organism*);
};
#endif // POISON_IVY_H
