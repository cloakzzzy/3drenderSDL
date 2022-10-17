#pragma once
#include<math.h>

class Camera {
public:
	int width; int height; int fov; int focal_length; int x; int y; int z; int degx;

	Camera(int Width, int Height, int Fov = 60, int X = 0, int Y = 0, int Z = 0, int Degx = 0)
	{
		width = Width; height = Height;
		fov = Fov;
		focal_length = round((width / 2) / tan((fov / 2) * RAD));
		x = X; y = Y; z = Z;
		degx = Degx;
	}
};