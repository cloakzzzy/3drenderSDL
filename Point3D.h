#pragma once
#include"Camera.h"
#include"Point2D.h"

class p3d {
public:
    int x; int y; int z;

    p3d() {
        x = 0; y = 0; z = 0;
    }

    p3d(int X, int Y, int Z) 
    {
        x = X;
        y = Y;
        z = Z;
    }
    void Set(int X, int Y, int Z) {
        x = X;
        y = Y;
        x = Z;
    }

    //projection
    int Projectx(Camera& cam)
    {
        return round(((x + cam.x) * cam.focal_length / (cam.focal_length + (z + cam.z))) + round(cam.width / 2));
    }
    int Projecty(Camera& cam)
    {
        return round((y + cam.y)*-1 * cam.focal_length / (cam.focal_length + (z + cam.z)) + round(cam.height / 2));
    }

    void Project(Camera& cam,p3d& point) 
    {
        point.x = round((x * cam.focal_length / (cam.focal_length + z)) + round(cam.width / 2));
        point.y = round(y * -1 * cam.focal_length / (cam.focal_length + z) + round(cam.height / 2));
    }

    //rotation
    static void rotateXZ(p3d& point, int cx, int cy, int px, int py, int deg = 1)
    {
        point.x = int((px * cos(deg * RAD)) - (py * sin(deg * RAD))) + cx;
        point.z = int((px * sin(deg * RAD)) + (py * cos(deg * RAD))) + cy;
    }
};