
#ifndef PLAYER_H
#define PLAYER_H

#include "sprite.h"

#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_LEFT 4
#define KEY_RIGHT 8

class Player : public Sprite
{
  private:

  protected:

  public:
  Player() : Sprite(){keys = 0;}
  Player(Rectangle r) : Sprite(r){keys = 0;}
  char keys;
  void event(SDL_Event);
};



#endif
