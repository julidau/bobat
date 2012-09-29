#include "bobat.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

using namespace std;

template <class T>
void printVec(vector3d<T> other)
{
	cout << other.getX() << "; ";
	cout << other.getY() << "; ";
	cout << other.getZ() << endl;
}
#include <assert.h>
int main(int argc, char ** args)
{
	initscr();

	scene testscene;
	testscene.props.width = 160;
	testscene.props.height = 40;


	testscene.Plist.push_back(new polygon(vector3df(-1,0,0),vector3df(-1,0,1),vector3df(-1,1,1)));

	camera testcam(vector3df(3,0,0),vector3df(-1,0,0), vector3df(0,0,1));
	cout << vector3df(1,0,0).crossProd(vector3df(0,0,1)).toString() << endl;
	core::array<coloru8 > image = testcam.render(testscene);

	for (u32 y = 0; y < testscene.props.height; y++)
	{
		for (u32 x = 0; x < testscene.props.width; x++)
		{
			if( image.at(x*testscene.props.height+y).getR() != 0 )
				//printw("\e[47m ");
				mvprintw(y,x,"1");
			else
				//printw("\e[41m ");
				mvprintw(y,x,"0");
		}
		//printw("\e[40m");
	}
	//printw("\e[40m ");
	refresh();
	getch();
	endwin();

	return 0;
}
