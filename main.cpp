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

	vector3df s(0,0,0);
	vector3df d(1,0.25,0);

	ray3df testray(s,d);

	polygon P(vector3df(2,-1,1),vector3df(1,2,1),vector3df(1,-1,3));

	vector3df iP;
	f32 u = 0;
	if(P.getCollision(testray,u,iP))
	{
		cout << u << endl;
		printVec<f32>(iP);
	}
	return 0;
}
