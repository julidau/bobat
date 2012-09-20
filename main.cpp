#include "bobat.h"
#include <iostream>
#include <math.h>

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
	ray3df testray(vector3df(0,0,0),vector3df(-1,-1,0));
	polygon P(vector3df(-3,1,1),vector3df(0,-1,2),vector3df(0,1,-1));

	vector3df iP;
	f32 u = 0;
	if(P.getCollision(testray,u,iP))
	{
		cout << u << endl;
		printVec<f32>(iP);
	}
	return 0;
}
