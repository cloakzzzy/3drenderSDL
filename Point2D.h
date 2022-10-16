#pragma once

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

    /*
    P2d rotate(int cx, int cy, int deg = 1)
    {
        P2d point;
        point.x = int((x * cos(deg * RAD)) - (y * sin(deg * RAD))) + cx;
        point.y = int((x * sin(deg * RAD)) + (y * cos(deg * RAD))) + cy;
        return point;
    }
    */
    
};