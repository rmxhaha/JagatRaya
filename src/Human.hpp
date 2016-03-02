#ifndef HUMAN_H
#define HUMAN_H

#include "Carnivore.hpp"

class Human : public Carnivore {
public:
    Human(Universe& universe, int x, int y, int t_lahir);
    virtual char ch() const ;
	virtual int umur() const;
	virtual int power() const;
    virtual float speed() const;

protected:
    void update_logic();
};

#endif // HUMAN_H
