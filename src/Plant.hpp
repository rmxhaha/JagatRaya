#include "Organism.hpp"
#include "Universe.hpp"

#ifndef PLANT_H
#define PLANT_H

class Plant : public Organism {
public:
    /** \brief Plant Constructor
     *
     * \param u universe it belongs in
     *
     */
	Plant(Universe& u, int x, int y,float currentAge);
    /** \brief update the plant
     *
     * \param see Organism::update
     * \return void
     *
     */
	void update(float dt);
    /** \brief update the plant
     *
     * \param see Organism::update
     * \return void
     *
     */
    float getTimebuffer() const;
protected:
    /** \brief do the logic of plant growing
     *
     * \return void
     *
     */
	virtual void update_grow();
    /** \brief grow new plant of the same class to the cell beside
     *
     * \return void
     *
     */
	virtual void grow() const =0;
    /** \brief time between producing another plant
     *
     * \return float the time between
     *
     */
	virtual float tgrow() const = 0;
	float timebuffer;
};


#endif
