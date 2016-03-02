#ifndef MAHKLUP_HIDUP
#define MAHKLUP_HIDUP

#include "board.hpp"

class Organism {
public:
	Organism(Board&, int x, int y, int t_lahir);

	bool isDead() const;
	bool isAlive() const;

	virtual char ch() const = 0;
	virtual int umur() const = 0;
	virtual int power() const = 0;
	virtual void update() = 0;
protected:

    void forceKill();

	int tlahir;
	bool is_dead;
	int x,y;
	Board& board;
};

#endif 
