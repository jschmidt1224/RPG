#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "init.h"
#include "timer.h"
#include "rectangle.h"
#include "sprite.h"
#include "character.h"
#include "local.h"


SDL_Surface* screen;
SDL_Event event;

int main(int argc, char* args[])
{
  bool quit;
  if (init(480, 640, 32))
    return 1;

  Timer delta;

  Rectangle rect = {50, 50, 32, 32};
  Sprite sprite(rect);
  sprite.surface = load_image("Block.bmp", true, 255, 255, 255);

  Local player(rect);
  player.surface = load_image("Block.bmp", true, 255, 255, 255);


  delta.start();

  while(quit == false)
  {
    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        quit = true;
      }
      player.event(event);

    }
    //perform step etc.

    sprite.step(delta.get_ticks());
    player.step(delta.get_ticks());

    //restart timer
    delta.start();


    //draw
    draw_rect(0, 0, 640, 480, 255, 255, 255, screen);
    sprite.draw();
    player.draw();

    SDL_Flip(screen);

  }

  return 0;
}
