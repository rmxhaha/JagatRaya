#ifndef MAHKLUP_HIDUP
#define MAHKLUP_HIDUP

class MahklupHidup {
public:
	MahklupHidup(Board&, int x, int y);

	bool isDead() const;
	bool isAlive() const;

	virtual char ch() const = 0;
	virtual int umur() const = 0;
	virtual int power() const = 0;
	virtual void update() = 0;

	void updateMap();
protected:
	int tlahir;
	bool isDead;
	int x,y;
	Board& board;
};

#endif MAHKLUP_HIDUP