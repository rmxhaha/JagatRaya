#include "board.hpp"
#include <conio.h>
#include <windows.h>


Board::Board()
{
	w=defaultsize;
	h=defaultsize;
	data = new string*[h];
	for(int i=0;i<h;i++)
	{
		data[i]=new string[w];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			data[i][j]="";
		}
	}

}

Board::Board(int _w, int _h)
{
	w=_w;
	h=_h;
	data= new string*[h];
	for(int i=0;i<h;i++)
	{
		data[i]=new string[w];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			data[i][j]="";
		}
	}

}

Board::Board(const Board& B)
{
	w=B.w;
	h=B.h;
	data = new string*[h];
	for(int i=0;i<h;i++)
	{
		data[i]=new string[w];
	}

	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			data[i][j]=B.data[i][j];
		}
	}

}

Board::~Board()
{
	w=0;
	h=0;
	delete data;
}
Board& Board::operator=(const Board& B)
{
	delete data;
	w=B.w;
	h=B.h;
	data = new string*[h];
	for(int i=0;i<h;i++)
	{
		data[i]=new string[w];
	}
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			data[i][j]=B.data[i][j];
		}
	}

	return *this;
}

const int Board::GetW()
{
	return w;
}

const int Board::GetH()
{
	return h;
}

string Board::GetEl(int _h,int _w)
{
	return data[_h][_w];
}

void Board::SetEl(char c,int _h,int _w)
{
	data[_h][_w]+=c;
}
void Board::DelEl(char c,int _h,int _w)
{
	string s=data[_h][_w];
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==c)
		{
			data[_h][_w].erase(i,1);
			break;
		}
	}
}

void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

void Board::PrintBoard()
{
	for(int i=0;i<h;i++)
	{
        gotoxy(0,i);
		for(int j=0;j<w;j++)
		{
		    if( data[j][i].length() > 0 )
                cout << data[j][i][0];
            else
                cout << " ";
		}
		cout << endl;
	}
}

bool Board::isEmpty() {
    for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
		    if( GetEl(j,i).length() > 0 )
                return false;
		}
	}
	return true;
}
