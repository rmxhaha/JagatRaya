#include "Herbivore.hpp"
#include "Race.hpp"
#include "RaceState.hpp"
#include "IsA.hpp"
#ifndef _RABBIT_H
#define _RABBIT_H
/**
 * Rabbit class.
 * Rabbit can eat plants.
 * Rabbit can race with turtle.
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
        /** \brief see Animal::update_logic
		*/
		void update_logic();
        /** \brief see Organism::ch
     	*/
		char ch() const;
        /** \brief see Animal::speed
     	*/
		float speed() const;
        /** \brief see Organism::power
     	*/
		int power() const;
        /** \brief see Organism::age
     	*/
		int age() const;
        /** \brief see Organism::interact
     	*/
		void interact(Organism*);
        /** Notify Rabbit about new Race.
        */
		void triggerRace(Race*);
    private:
        Race* Ra;
};
#endif // RABBIT_H
