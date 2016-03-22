#include "Herbivore.hpp"
#include "IsA.hpp"
#include "Race.hpp"
#include "RaceState.hpp"

#ifndef _TURTLE_H
#define _TURTLE_H

/**
 * Turtle class.
 * Turtle can have a race with rabbit class , one race just have one rabbit and one turtle.
 * Turtle can eat object from plant class.
 */
class Turtle:public Herbivore{
    public:
    /** \brief Turtle Constructor
     *
     * \param universe Universe it belong in
     * \return Turtle
     *
     */
    	Turtle(Universe& u,int x,int y,float currentAge);
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
        Race* R;

};
#endif // _TURTLE_H
