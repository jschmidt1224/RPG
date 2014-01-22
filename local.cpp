#include "local.h"

void Local::event(SDL_Event event)
{
  double vX, vY;
  Rect r;
  if(event.type == SDL_KEYDOWN)
  {
    switch(event.key.keysym.sym)
    {
      case SDLK_UP: keys |= KEY_UP; break;
      case SDLK_DOWN: keys |= KEY_DOWN; break;
      case SDLK_LEFT: keys |= KEY_LEFT; break;
      case SDLK_RIGHT: keys |= KEY_RIGHT; break;
      default: break;
    }
  }
  else if(event.type == SDL_KEYUP)
  {
    switch(event.key.keysym.sym)
    {
      case SDLK_UP: keys &= ~KEY_UP; break;
      case SDLK_DOWN: keys &= ~KEY_DOWN; break;
      case SDLK_LEFT: keys &= ~KEY_LEFT; break;
      case SDLK_RIGHT: keys &= ~KEY_RIGHT; break;
      default: break;
    }
  }

  if(keys & KEY_UP)
  {
    vY = -200;
  }
  else if(keys & KEY_DOWN)
  {
    vY = 200;
  }
  else
    vY = 0;

  if(keys & KEY_LEFT)
  {
    vX = -200;
  }
  else if(keys & KEY_RIGHT)
  {
    vX = 200;
  }
  else
    vX = 0;

  r.x = vX;
  r.y = vY;

  set_speed(r);
}
