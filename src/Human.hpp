#ifndef HUMAN_H
#define HUMAN_H

#include "Carnivore.hpp"
/**
 * Human class.
 * Human can copulate with other Human but has a limit in the number of offspring to prevent overpopulation.
 */
class Human : public Carnivore {
public:
    /** \brief Human Constructor
     *
     * \param universe Universe it belong in
     * \return Human
     *
     */
    Human(Universe& universe, int x, int y,float currentAge);
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
    int offspringCount;
    void copulate();
    void update_logic();
    static const int maxOffspring = 2;
};

#endif // HUMAN_H
