
#ifndef CHARACTER_H
#define CHARACTER_H

#include "sprite.h"

#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_LEFT 4
#define KEY_RIGHT 8

class Character : public Sprite
{
  private:

  protected:

  public:
  Character() : Sprite(){};
  Character(Rect r) : Sprite(r){};
  void step(int);
};



#endif

