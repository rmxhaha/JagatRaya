#ifndef _BOARD_H
#define _BOARD_H
#include <iostream>
using namespace std;
class Board
{
public:
	Board();
	Board(int _w,int _h);
	Board(const Board& B);
	~Board();
	Board& operator=(const Board& B);
	int GetW();
	int GetH();
	char GetEl(int _h,int _w);
	void SetW(int _w);
	void SetH(int _h);
	void SetEl(char c,int _h,int _w);
	void PrintBoard();
private:
	char **data;
	static const int defaultsize = 10;
	int w;
	int h;
	
};
#endif
