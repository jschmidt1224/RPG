
#ifndef LOCAL_H
#define LOCAL_H

#include "character.h"

#define KEY_UP 1
#define KEY_DOWN 2
#define KEY_LEFT 4
#define KEY_RIGHT 8

class Local : public Character
{
  private:

  protected:

  public:
  Local() : Character(){keys = 0;};
  Local(Rect r) : Character(r){keys = 0;};
  void event(SDL_Event);
  char keys;
};



#endif
