#include "Animal.hpp"

#ifndef Herbivore_H
#define Herbivore_H

class Herbivore : public Animal {
public:
	/** \brief Herbivore Constructor
     *
     * \param universe Universe it belong in
     * \return Herbivore
     *
     */
    Herbivore(Universe& u, int x, int y, float currentAge);

protected:

};

#endif
