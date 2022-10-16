#pragma once
#include<math.h>
#include<string>
#include<thread>
#include<windows.h>
#include<future>

//#define RAD 3.14159265358/180 

#define RAD 3.14159265358/180 


using namespace std;


bool m; bool z;
void alternate(int &a, int min, int max, int inc)
{
	// check if a is 'min', if a is zero then 'z' equals true
	if (a == min) { z = true; m = false; }

	// if 'z' equals true then increment a
	if (z == true) { a += inc; }

	//if a equals 'max' then 'm' = true 
	if (a == max) { m = true; z = false; }

	//if 'm' equals true then a decrements
	if (m == true) { a -= inc; }

}

void rotateXZ(int point[],int cx, int cy, int px,int py, int deg = 1)
{
	point[0] = int((px * cos(deg *RAD)) - (py * sin(deg *RAD))) + cx;
	point[1] = int((px * sin(deg *RAD)) + (py * cos(deg *RAD))) + cy;
}

void project(int point[], int fov, int width,int height,int x, int y, int z)
{
	y *= -1;
	int fl  =  round((width / 2) / tan((fov/2) * RAD));
	point[0] = round((x * fl / (fl + z))+round(width/2));
	point[1] = round(y * fl / (fl + z)+round(height/2));
}

/*
static void rotateXZ(P3d &point, int cx, int cy, int px, int py, int deg = 1)
	{
		point.x = int((px * cos(deg * RAD)) - (py * sin(deg * RAD))) + cx;
		point.z = int((px * sin(deg * RAD)) + (py * cos(deg * RAD))) + cy;
	}
*/

/*
void rotateXZ(int cx, int cz, int deg = 1)
	{
		x -= cx; z -= cz;

		x = round((x * cos(deg * RAD)) - (z * sin(deg * RAD))) + cx;
		z = round(((x-cz)* sin(deg * RAD)) + (z * cos(deg * RAD))) + cz;

		//cout << round((x * cos(deg * RAD)) - (z * sin(deg * RAD))) << " " << round((x * sin(deg * RAD)) + (z * cos(deg * RAD))) << '\n';
	}
*/


