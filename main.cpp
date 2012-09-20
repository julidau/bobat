#include "bobat.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class T>
void printVec(vector3d<T> other)
{
	cout << other.getX() << "; ";
	cout << other.getY() << "; ";
	cout << other.getZ() << endl;
}

int main()
{
	scene testscene;
	testscene.props.width = 1920;
	testscene.props.height = 1080;


	testscene.Plist.push_back(new polygon(vector3df(2,0,0),vector3df(0,0,-1),vector3df(0,1,0)));

	camera testcam(vector3df(0,0,0),vector3df(1,0,0));

	core::array<coloru8 > image = testcam.render(testscene);
	//image.allocate(80*25);

	for (u32 y = 0; y < 25; y++)
	{
		for (u32 x = 0; x < 80; x++)
		{
			//image.at(x*80+y).setR(rand()%2);
			if( image.at(x*80+y).getR() != 0 )
				cout << "\e[47m ";
			else
				cout << "\e[41m ";
		}
		cout << endl;
	}
	cout << "\e[40m ";
	return 0;
}
