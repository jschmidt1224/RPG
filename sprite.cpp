
#include "sprite.h"

extern SDL_Surface* screen;
extern void draw_surface(Rectangle, SDL_Surface*, SDL_Surface*);

Sprite::Sprite()
{
  position_.x = 0;
  position_.y = 0;
  position_.w = 0;
  position_.h = 0;
  speed_.x = 0;
  speed_.y = 0;
  speed_.w = 0;
  speed_.h = 0;
  surface = NULL;
}

Sprite::Sprite(Rectangle position)
{
  position_.x = position.x;
  position_.y = position.y;
  position_.w = position.w;
  position_.h = position.h;
  speed_.x = 0;
  speed_.y = 0;
  speed_.w = 0;
  speed_.h = 0;
  surface = NULL;
}

char Sprite::collision_check(Sprite sprite, Rectangle offset)
{
  float aT, bT, aB, bB, aR, bR, aL, bL;
  char ret;
  aT = position_.y + offset.y;
  bT = sprite.position_.y;
  aB = aT + position_.h;
  bB = bT + sprite.position_.h;
  aL = position_.x + offset.x;
  bL = sprite.position_.x;
  aR = aL + position_.w;
  bR = bL + sprite.position_.w;
  if(aB <= bT)
    return 0;
  else if(aT >= bB)
    return 0;
  else if(aR <= bL)
    return 0;
  else if( aL >= bR)
    return 0;

  if (aL < bR)
    ret |= HIT_LEFT;
  if (aB > bT)
    ret |= HIT_BOTTOM;
  if (aR > bL)
    ret |= HIT_RIGHT;
  if (aT < bB)
    ret |= HIT_TOP;

  return ret;
}

void Sprite::draw()
{
  draw_surface(position_, surface, screen);
}

void Sprite::step(int time)
{
  position_.x += speed_.x * (time / 1000.0f);
  position_.y += speed_.y * (time / 1000.0f);
}

Rectangle Sprite::get_position()
{
  return position_;
}

Rectangle Sprite::get_speed()
{
  return speed_;
}

Rectangle Sprite::get_previous()
{
  return previous_;
}

void Sprite::set_position(Rectangle position)
{
  position_.x = position.x;
  position_.y = position.y;
  position_.w = position.w;
  position_.h = position.h;
}

void Sprite::set_speed(Rectangle speed)
{
  speed_.x = speed.x;
  speed_.y = speed.y;
  speed_.w = speed.w;
  speed_.h = speed.h;
}

