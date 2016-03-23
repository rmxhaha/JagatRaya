#ifndef ORGANISM_FACTORY_H
#define ORGANISM_FACTORY_H


#include "Universe.hpp"
#include "Organism.hpp"

/**
 * OrganismFactory class.
 * OrganismFactory simplfies spawning orgnaism n a certain universe
 */

class OrganismFactory {
public:
	/** \brief OrganismFactory Constructor
     *
     * \param universe Universe to spawn organism
     * \param currentAge Current Age template for spawned organism
     * \return OrganismFactory
     *
     */
	OrganismFactory(Universe& _u, float = 10);

	/** \brief set current age template
     */
	void SetCurrentAge(float);

	/** \brief create random organism at random place
     */
	Organism* CreateRandom();
	/** \brief create random organism at x, y
	 * \param x
     * \param y
     * \return Organism*
     */
	Organism* CreateRandomAt(int,int);

	/** \brief create Deer organism at x, y
	 * \param x
     * \param y
     * \return Organism*
     */
	Organism* CreateDeer(int,int);
	/** \brief create Tiger organism at x, y
	 * \param x
     * \param y
     * \return Organism*
     */
	Organism* CreateTiger(int,int);
	/** \brief create Alien organism at x, y
	 * \param x
     * \param y
     * \return Organism*
     */
	Organism* CreateAlien(int,int);
	/** \brief create Eagle organism at x, y
	 * \param x
     * \param y
     * \return Organism*
     */
	Organism* CreateEagle(int,int);
	/** \brief create Grass organism at x, y
	 * \param x
     * \param y
     * \return Organism*
     */
	Organism* CreateGrass(int,int);
	/** \brief create Human organism at x, y
	 * \param x
     * \param y
     * \return Organism*
     */
	Organism* CreateHuman(int,int);
	/** \brief create PoisonIvy organism at x, y
	 * \param x
     * \param y
     * \return Organism*
     */
	Organism* CreatePoisonIvy(int,int);
	Organism* CreateRabbit(int,int);
	Organism* CreateTurtle(int,int);
private:
	Universe *u;
	float currentAge;
};

#endif
