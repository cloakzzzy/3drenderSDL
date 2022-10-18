#pragma once
#include"Camera.h"
#include"Point2D.h"

#define RAD 3.14159265358/180 

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

    //rotation
    static void rotateXZ(p3d& point, int cx, int cy, int px, int py, int deg = 1)
    {
        point.x = int((px * cos(deg * RAD)) - (py * sin(deg * RAD))) + cx;
        point.z = int((px * sin(deg * RAD)) + (py * cos(deg * RAD))) + cy;
    }

    void Set(int X, int Y, int Z) {
        x = X;
        y = Y;
        x = Z;
    }

    //projection
    int Projectx(Camera& cam)
    {
        return round(((x + cam.x*-1) * cam.focal_length / (cam.focal_length + (z + cam.z*-1))) + round(cam.width / 2));
    }
    int Projecty(Camera& cam)
    {
        return round((y + cam.y*-1)*-1 * cam.focal_length / (cam.focal_length + (z + cam.z*-1)) + round(cam.height / 2));
        
    }
    
    bool Visible(Camera& cam)
    {
        // visible = false | if x is smaller than xboundleft
        // or 
        // visible = false | if x is larger than xboundright
        // or
        // visible = false | if y is larger than yboundtop
        // or 
        // visible = false | if y is smaller than yboundbottom

        int length = round(cam.width + 2 * (tan(cam.fov / 2 * RAD) * (z - cam.z)));
        int xboundleft = cam.x - (length) / 2;
        int xboundright = cam.x + (length) / 2;
        int yboundtop = cam.y - (length) / 2;
        int yboundbottom = cam.y + (length) / 2;

        //cout <<x<<" "<< "X: " << xboundleft << " " << xboundright <<" "<<y<<" Y: " << yboundtop << " " << yboundbottom << '\n';

        
        
        if ((x < xboundleft) or (x > xboundright) or (y < yboundtop) or (y > yboundbottom)) {
            return false;
        }
        else
        {
            return true;
        }
        
        
        
    }
};