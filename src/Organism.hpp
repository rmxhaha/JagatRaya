#ifndef MAHKLUP_HIDUP
#define MAHKLUP_HIDUP


#include "Universe.hpp"

class Universe;
class Organism {
public:
	Organism(Universe& u, int x, int y, float currentAge);

	int getX();
	int getY();

	bool isDead() const;
	bool isAlive() const;

    /** \brief ch is a character of the organism it represents
     * \return char of the organism it represent
     */
	virtual char ch() const = 0;
	virtual int age() const = 0;
	virtual int power() const = 0;
	virtual void update(float dt); // delta time in milliseconds
	virtual void interact(Organism*) = 0;

    void forceKill();
protected:
    float cAge; // current age
	bool is_dead;
	int x,y;
	Universe* universe;
};

#endif
