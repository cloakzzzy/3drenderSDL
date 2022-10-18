#pragma once

#define RAD 3.14159265358/180 

class p2d {        
public:     
    int x; int y;

    p2d()
    {
        x = 0;
        y = 0;
    }
    p2d(int X, int Y)
    {
        x = X;
        y = Y;
    }
    
    void Set(int X, int Y) 
    {
        x = X;
        y = Y;
    }

    static void rotateXZ(p2d& point, int cx, int cy, int px, int py, int deg = 1)
    {
        point.x = int((px * cos(deg * RAD)) - (py * sin(deg * RAD))) + cx;
        point.y = int((px * sin(deg * RAD)) + (py * cos(deg * RAD))) + cy;
    }
    
    
};