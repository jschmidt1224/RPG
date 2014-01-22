
#ifndef SPRITE_H
#define SPRITE_H

#include "SDL/SDL.h"
#include "Rectangle.h"

#define HIT_TOP 1
#define HIT_BOTTOM 2
#define HIT_LEFT 4
#define HIT_RIGHT 8

class Sprite
{
  protected:
  Rect position_;
  Rect speed_;
  Rect previous_;
  public:
  SDL_Surface* surface;

  Sprite();
  Sprite(Rect);

  char collision_check(Sprite, Rect);
  void draw();
  void step(int);

  Rect get_position();
  Rect get_speed();
  Rect get_previous();

  void set_position(Rect);
  void set_speed(Rect);
};


#endif
