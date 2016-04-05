import java.io.*;
class Board
{
	//ATRIBUTE
	private String [][] data;
	private int defaultsize = 10;
	private int w;
	private int h;
	//METHOD
	public Board(){
		w=defaultsize;
		h=defaultsize;
		data = new String[h][w];
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				data[i][j]="";
			}
		}
	}
	public Board(int _w,int _h){
		w=_w;
		h=_h;
		data= new String[h][w];
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				data[i][j]="";
			}
		}
	}
	public Board(Board B){
		w=B.w;
		h=B.h;
		data= new String[h][w];
		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				data[i][j]=B.data[i][j];
			}
		}
	}
	public int GetW() { return w;}
	public int GetH() { return h;}
	public String GetEl(int _h,int _w) { return data[_h][_w];}
	public void SetEl(char c,int _h,int _w){ data[_h][_w]+=c; }
	public void DelEl(char c,int _h,int _w){ 
		String s=Character.toString(c);
		data[_h][_w]=data[_h][_w].replaceFirst(s,"");
	}
	/*public void gotoxy( int column, int line )
	 {
	  COORD coord;
	  coord.X = column;
	  coord.Y = line;
	  SetConsoleCursorPosition(
		GetStdHandle( STD_OUTPUT_HANDLE ),
		coord
		);
	}*/
	public void PrintBoard(){
		for(int i=0;i<h;i++)
		{
			gotoxy(0,i);
			for(int j=0;j<w;j++)
			{
				if( data[j][i].length() > 0 )
					System.out.print (data[j][i].charAt(0));
				else
					System.out.print(" ");
			}
			System.out.println(" ");
		}
	}
    public boolean isEmpty(){
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

};