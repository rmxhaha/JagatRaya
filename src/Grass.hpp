#ifndef GRASS_H
#define GRASS_H
#include "IsA.hpp"
#include "Plant.hpp"
/**
 * Grass class.
 * Grass can grow around.
 */
class Grass : public Plant {
	public:
		/** \brief Grass Constructor
	     *
	     * \param universe Universe it belong in
	     * \return Grass
	     *
	     */
		Grass(Universe&, int x, int y,float currentAge);
		/** \brief see Plant::grow
     	*/
		void grow() const;
		/** \brief see Organism::power
     	*/
		int power() const;
		/** \brief see Plant::tgrow
     	*/
		float tgrow() const ;
		/** \brief see Organism::ch
     	*/
		char ch() const ;
		/** \brief see Organism::age
     	*/
		int age() const;
		/** \brief see Plant::update_grow
     	*/
		void update_grow() ;
		/** \brief see Organism::interact
     	*/
		void interact(Organism*);
};
#endif // GRASS_H
