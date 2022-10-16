#pragma once
#include"Point3D.h"
#include<vector>

using namespace std;

class p3dVec{
private:
	
public:
	vector<p3d> p;
	vector<p3d>& points = p;
	
	p3dVec() {}
	void Translate(int x = 0, int y = 0, int z = 0)
	{
		cout << points.size() << '\n';
		for (int i = 0; i < points.size(); i++)
		{
			points[i].x += x;
			points[i].y += y;
			points[i].z += z;
		}
	}
};