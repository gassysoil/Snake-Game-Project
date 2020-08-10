#ifndef GAMER_H
#define GAMER_h

#include "snake.h"
#include "SDL.h"

class Gamer {
 public:
  Gamer(const Snake* snake, const SDL_Point* food);
  ~Gamer();
  void play();
 
 private:
  const Snake* snake;
  const SDL_Point* food;
};

#endif
