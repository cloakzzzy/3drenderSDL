// g++ main.cpp `pkg-config --cflags --libs sdl2`
//second commit 
//gfhgfdgsggsgfdgd
#include <SDL.h>
#include <iostream>
#include<windows.h>
#include<math.h>
#include"Utillities.h"
#include<string>
#include"SDL_Abstraction.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Camera.h"
#include"p3dVec.h"
#include<vector>

using namespace std;

int main(int argc, char** argv)
{

    //project(60,500,500,200,0,200);

    SDLWindow window("3d render using SDL2", 500, 100, 500, 500,0,0,0);
    
    int deg = -1;
    int deg2 = -3;

    int rotationsc = 0;
    int Elapsed = 0;
    int frames = 0;
    int rotations = 0;

    //defualt -50, 50
    
    Camera cam(window.W, window.H, 90);
    vector <p3d> ps{
        //bottom face
        //top left 
        p3d(-50,-100,50),
        //top right
        p3d(50,-100,50),
        //bottom left
        p3d(-50,-100,-50),
        //bottom right
        p3d(50,-100,-50),

        //top face
        // top left
        p3d(-50,100,50),
        //top right
        p3d(50,100,50),
        //bottom left
        p3d(-50,100,-50),
        //bottom right
        p3d(50,100,-50),
    };

    p2d ps2[8];
    int z = 200;
    deg = -1;
    
    window.InitWindow();
    bool rotate = false;
    bool rotated = false;

    thread motionthread([&]() {
        while (window.Running) {
            Sleep(1);
            if (rotate == true) 
            {
                //bottom points rotation

                //top left 
                p3d::rotateXZ(ps[0], 0, 0 + z, -50, 50, deg);
                //top right
                p3d::rotateXZ(ps[1], 0, 0 + z, 50, 50, deg);
                //bottom left
                p3d::rotateXZ(ps[2], 0, 0 + z, -50, -50, deg);
                //bottom right
                p3d::rotateXZ(ps[3], 0, 0 + z, 50, -50, deg);

                //top points rotation

                //top left 
                p3d::rotateXZ(ps[4], 0, 0 + z, -50, 50, deg);
                //top right
                p3d::rotateXZ(ps[5], 0, 0 + z, 50, 50, deg);
                //bottom left
                p3d::rotateXZ(ps[6], 0, 0 + z, -50, -50, deg);
                //bottom right
                p3d::rotateXZ(ps[7], 0, 0 + z, 50, -50, deg);
                rotated = true;
            }
        }
        });

    window.Mainloop([&] {

        Sleep(3);
        SDL_SetRenderDrawColor(window.renderer, 255, 255, 255, 255);

        SDL_Event eve;

        while (SDL_PollEvent(&eve))
        {

            if (eve.type == SDL_KEYDOWN)
            {
                if (eve.key.keysym.scancode == SDL_SCANCODE_D)
                {
                    cam.x -= 20;
                }
                if (eve.key.keysym.scancode == SDL_SCANCODE_A)
                {
                    cam.x += 20;
                }
                if (eve.key.keysym.scancode == SDL_SCANCODE_W)
                {
                    cam.z -= 20;
                }
                if (eve.key.keysym.scancode == SDL_SCANCODE_S)
                {
                    cam.z += 20;
                }
                if (eve.key.keysym.scancode == SDL_SCANCODE_SPACE)
                {
                    cam.y -= 20;
                }
                if (eve.key.keysym.scancode == SDL_SCANCODE_LSHIFT)
                {
                    cam.y += 20;
                }

            }

        }
        
        deg -= 1;
        rotate = true;
        //alternate(z, -170, 200, 1);

        //projection
        if (rotated == true)
        {
            ps2[0].Set(ps[0].Projectx(cam), ps[0].Projecty(cam));
            ps2[1].Set(ps[1].Projectx(cam), ps[1].Projecty(cam));
            ps2[2].Set(ps[2].Projectx(cam), ps[2].Projecty(cam));
            ps2[3].Set(ps[3].Projectx(cam), ps[3].Projecty(cam));
            ps2[4].Set(ps[4].Projectx(cam), ps[4].Projecty(cam));
            ps2[5].Set(ps[5].Projectx(cam), ps[5].Projecty(cam));
            ps2[6].Set(ps[6].Projectx(cam), ps[6].Projecty(cam));
            ps2[7].Set(ps[7].Projectx(cam), ps[7].Projecty(cam));
            rotated = false;
        }
       
        //render
        
        //bottom points
        //top line - top left to top right
        SDL_RenderDrawLine(window.renderer, ps2[0].x, ps2[0].y, ps2[1].x, ps2[1].y);
        //right line - top right to bottom right
        SDL_RenderDrawLine(window.renderer, ps2[1].x, ps2[1].y, ps2[3].x, ps2[3].y);
        //bottom line - bottom left to bottom right
        SDL_RenderDrawLine(window.renderer, ps2[2].x, ps2[2].y, ps2[3].x, ps2[3].y);
        //left line - top left to bottom left
        SDL_RenderDrawLine(window.renderer, ps2[0].x, ps2[0].y, ps2[2].x, ps2[2].y);

        //top points
        SDL_RenderDrawLine(window.renderer, ps2[4].x, ps2[4].y, ps2[5].x, ps2[5].y);
        //right line - top right to bottom right
        SDL_RenderDrawLine(window.renderer, ps2[5].x, ps2[5].y, ps2[7].x, ps2[7].y);
        //bottom line - bottom left to bottom right
        SDL_RenderDrawLine(window.renderer, ps2[6].x, ps2[6].y, ps2[7].x, ps2[7].y);
        //left line - top left to bottom left
        SDL_RenderDrawLine(window.renderer, ps2[4].x, ps2[4].y, ps2[6].x, ps2[6].y);

        //connecting lines
        SDL_RenderDrawLine(window.renderer, ps2[4].x, ps2[4].y, ps2[0].x, ps2[0].y);
        SDL_RenderDrawLine(window.renderer, ps2[5].x, ps2[5].y, ps2[1].x, ps2[1].y);
        SDL_RenderDrawLine(window.renderer, ps2[6].x, ps2[6].y, ps2[2].x, ps2[2].y);
        SDL_RenderDrawLine(window.renderer, ps2[7].x, ps2[7].y, ps2[3].x, ps2[3].y);

        

        SDL_RenderPresent(window.renderer);

        if (deg == 360) { deg = -1; }
        
       
        
    }, 1);
    
    motionthread.detach();
    window.Destroy();

    return 0;
}