
#ifndef SPRITE_H
#define SPRITE_H

#include "SDL/SDL.h"
#include "rectangle.h"

#define HIT_TOP 1
#define HIT_BOTTOM 2
#define HIT_LEFT 4
#define HIT_RIGHT 8

class Sprite
{
  protected:
  Rectangle position_;
  Rectangle speed_;
  Rectangle previous_;
  public:
  SDL_Surface* surface;

  Sprite();
  Sprite(Rectangle);

  char collision_check(Sprite, Rectangle);
  void draw();
  void step(int);

  Rectangle get_position();
  Rectangle get_speed();
  Rectangle get_previous();

  void set_position(Rectangle);
  void set_speed(Rectangle);
};


#endif
