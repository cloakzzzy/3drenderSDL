#pragma once
#include<SDL.h>

using namespace std;

class SDLWindow {
public:
    SDL_Window* winobject;
    SDL_Renderer* renderer;
    bool Running = true;
    const char* Title; int X; int Y; int W; int H;
    int R; int G; int B; int A; 

    SDLWindow(const char* title, int x, int y, int w, int h,int r = 242 ,int g = 242, int b = 242, int a = 255) {
        Title = title; 
        X = x; Y = y;
        W = w; H = h;
        R = r; G = g;
        B = b; A = a;
  
    }

	void InitWindow() {
        SDL_Init(SDL_INIT_EVERYTHING);
        winobject = SDL_CreateWindow(Title, X, Y, W, H, SDL_WINDOW_SHOWN);

        if (!winobject)
        {
            cout << "Failed to create a window! Error: " << SDL_GetError() << "\n";
        }
        renderer = SDL_CreateRenderer(winobject, -1, SDL_RENDERER_ACCELERATED);
        Running = true;
	}

    void Mainloop(function<void()> func,int loopdelay = 1, int keystate = SDL_KEYDOWN, int endkey = SDL_SCANCODE_ESCAPE)
    {
        while (Running)
        {
            this_thread::sleep_for(chrono::milliseconds(loopdelay));
            SDL_Event ev;
            while (SDL_PollEvent(&ev))
            {
                if ((ev.type == SDL_QUIT) || (ev.type == keystate && ev.key.keysym.scancode == endkey))
                { 
                    Running = false; 
                    break; 
                }
            }
            SDL_SetRenderDrawColor(renderer, R, G, B, A);
            SDL_RenderClear(renderer);

            func();
        }
    }

    void Destroy() {
        SDL_DestroyWindow(winobject);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }

};
