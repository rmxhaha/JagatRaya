#ifndef MAHKLUP_HIDUP
#define MAHKLUP_HIDUP


#include "Universe.hpp"

class Universe;
class Organism {
public:
	Organism(Universe& u, int x, int y, int t_lahir);

	int getTLahir();
	int getX();
	int getY();

	void setTLahir(int tlahir);
    void setX(int x);
    void setY(int y);
    void setXY(int x, int y);

	bool isDead() const;
	bool isAlive() const;

	virtual char ch() const = 0;
	virtual int age() const = 0;
	virtual int power() const = 0;
	virtual void update(float dt) = 0; // delta time in milliseconds
	virtual void interact(Organism*) = 0;

    void forceKill();
protected:

	int tlahir;
	bool is_dead;
	int x,y;
	Universe* universe;
};

#endif
