#include "Herbivore.hpp"
#include "Race.hpp"
#include "RaceState.hpp"
#include "IsA.hpp"
#ifndef _RABBIT_H
#define _RABBIT_H

/**
 * Rabbit class.
 * Rabbit can have a race with turtle class , one race just have one rabbit and one turtle
 */

class Rabbit: public Herbivore {
    public:
    /** \brief Rabbit Constructor
     *
     * \param universe Universe it belong in
     * \return Rabbit
     *
     */
        Rabbit(Universe& u,int x,int y,float currentAge);
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
    void triggerRace(Race*);
    private:
        Race* Ra;
};
#endif // _RABBIT_H
