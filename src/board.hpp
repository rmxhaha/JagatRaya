#ifndef _BOARD_H
#define _BOARD_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
class Board
{
public:
	Board();
	Board(int _w,int _h);
	Board(const Board& B);
	~Board();
	Board& operator=(const Board& B);
	const int GetW();
	const int GetH();
	string GetEl(int _h,int _w);
	void SetEl(char c,int _h,int _w);
	void DelEl(char c,int _h,int _w);
	void PrintBoard();
private:
	string **data;
	static const int defaultsize = 10;
	int w;
	int h;

};
#endif
