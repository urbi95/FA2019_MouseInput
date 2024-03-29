#include <iostream>
#include <SDL.h>

#include "Square.h"

const int SCREEN_WIDTH  = 640;
const int SCREEN_HEIGHT = 480;
const int SQUARE_WIDTH  = 20;

bool init(SDL_Window** win, SDL_Renderer** ren){
    bool success = true;

    //Always check for errors while initializing
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        success = false;
    }
    else {
        *win = SDL_CreateWindow("Drag the square!", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (*win == nullptr){
            std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        else {
            *ren = SDL_CreateRenderer(*win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (*ren == nullptr){
                std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
                success = false;
            }
        }
    }

    return success;
}

void updateScreen(Square square, SDL_Renderer* ren){
    //Clear screen
    SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(ren);
    //Render square with renderer
    square.render(ren);
    SDL_RenderPresent(ren);
}

int main() {
    Square square = Square((SCREEN_WIDTH - SQUARE_WIDTH) / 2, (SCREEN_HEIGHT - SQUARE_WIDTH) / 2, SQUARE_WIDTH);
    bool quit = false;
    bool dragging = false;
    int mouseX;
    int mouseY;
    int relX=0;
    int relY=0;

    SDL_Window* win = nullptr;
    SDL_Renderer* ren = nullptr;
    SDL_Event e;

    if (init(&win, &ren)){
        while (!quit){
            //Draw square
            updateScreen(square, ren);

            while (SDL_PollEvent(&e) != 0){
                SDL_GetMouseState(&mouseX, &mouseY);

                if (e.type == SDL_QUIT){
                    quit = true;
                }
                else if (e.type == SDL_MOUSEBUTTONDOWN){
                    if (square.isInside(mouseX, mouseY)){
                        //We clicked inside the square
                        dragging = true;
                        relX = square.getX() - mouseX;
                        relY = square.getY() - mouseY;
                    }
                }
                else if (e.type == SDL_MOUSEBUTTONUP){
                    dragging = false;
                }

                if (dragging){
                    square.setX(relX + mouseX);
                    square.setY(relY + mouseY);

                    updateScreen(square, ren);
                }
            }
        }
    }

    //Clean up window and renderer
    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(ren);
    SDL_Quit();

    return 0;
}