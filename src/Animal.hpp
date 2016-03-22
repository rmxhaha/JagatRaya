#include "Organism.hpp"
#include "Direction.hpp"

#ifndef ANIMAL_H
#define ANIMAL_H



class Animal : public Organism {
public:
	/** \brief Animal Constructor
     *
     * \param universe Universe it belong in
     * \return Animal
     *
     */
	Animal(Universe& u, int x, int y,float currentAge);
	/** \brief speed of animal for moving
	* 	\return float
	*/
	virtual float speed() const = 0;
	/** \brief Time buffer of the animal
	 * 	\return float
	*/
    float getTimebuffer() const;
	/** \brief do the animal behaviour if reach time.
	 *  \param dt delta time for doing the animal behaviour 
	*/
    void update(float dt);
protected:
	/** \brief find the direction where animal should move to, if the animal want to run from its predator.
	 * 	\param x,y Location of the thing animal should avoid
	 * 	\return direction_t
	*/
	direction_t avoid(int x, int y);
	/** \brief find the direction where animal should move to, if the animal want to go to its prey / herd.
	 * 	\param x,y Location of the thing animal should go to.
	 * 	\return direction_t
	*/
	direction_t goTo(int x, int y);
	/** \brief return random direction.
	 * 	\return direction_t
	*/
	direction_t goRandom();
	/** \brief find the nearest target from the Animal
	 *  \param prey_ch symbol of the target
	 * 	\param prey_x, prey_y Location of the prey
	 * 	\param predator_x,predator_y Location of the Animal
	*/
	bool findPrey(char prey_ch,int & prey_x,int & prey_y,int predator_x,int predator_y);
	/** \brief move to the direction
	 *  \param direction direction where the animal should move to
	*/
	void move(direction_t direction);
    /** \brief behaviour of the animal
	*/
	virtual void update_logic();

    float timebuffer;
};


#endif // ANIMAL_H

