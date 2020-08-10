#include <iostream>
#include "gamer.h"

Gamer::Gamer(const Snake* snake, const SDL_Point* food) : snake(snake), food(food){
    std::cout << "Call Gamer's Constructor.\n";
};

Gamer::~Gamer() {
    std::cout << "Call Gamer's Destructor.\n";
}

void Gamer::play()
{
    int cur_x = static_cast<int>(snake->head_x);
    int cur_y = static_cast<int>(snake->head_y);

    if (cur_x != food->x && cur_y != food->y) return;
    if (cur_x == food->x && cur_y == food->y) return;
    
    SDL_Event sdlevent;
    sdlevent.type = SDL_KEYDOWN;

    if (cur_x == food->x) 
    {
        if (cur_y > food->y) sdlevent.key.keysym.sym = SDLK_UP;
        else sdlevent.key.keysym.sym = SDLK_DOWN;
    }
    else
    {
        if (cur_x > food->x) sdlevent.key.keysym.sym = SDLK_LEFT;
        else sdlevent.key.keysym.sym = SDLK_RIGHT;
    }

    SDL_PushEvent(&sdlevent);
}