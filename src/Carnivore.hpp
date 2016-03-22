#include "Animal.hpp"

#ifndef CARNIVORE_H
#define CARNIVORE_H

class Carnivore : public Animal {
public:
	/** \brief Carnivore Constructor
     *
     * \param universe Universe it belong in
     * \return Carnivore
     *
     */
    Carnivore(Universe&, int x, int y,float currentAge);

protected:

};

#endif
