

#ifndef INIT_H
#define INIT_H

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "Rectangle.h"


extern SDL_Surface* screen;

bool init(int screen_height, int screen_width, int screen_bpp)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
    return true;

  if ((screen = SDL_SetVideoMode(screen_width, screen_height, screen_bpp, SDL_SWSURFACE)) == NULL)
    return true;

  SDL_WM_SetCaption("Cooper RPG", NULL);

  return false;
}

SDL_Surface* load_image(std::string filename, bool trans = false, int r = 0, int g = 0, int b = 0)
{
    SDL_Surface* image = NULL;
    SDL_Surface* optimized = NULL;
    image = IMG_Load(filename.c_str()); //loads image
    if (image != NULL)
    {
        optimized = SDL_DisplayFormat(image);
        SDL_FreeSurface(image);
    }
    if (optimized != NULL && trans)
    {
        Uint32 colorkey = SDL_MapRGB(optimized->format, r, g, b);
        SDL_SetColorKey(optimized, SDL_SRCCOLORKEY, colorkey);
    }
    return optimized;
}

void draw_surface(Rect X, SDL_Surface* source, SDL_Surface* destination)
{
    SDL_Rect offset; //creates and set values for offset
    offset.x = (int)round(X.x);
    offset.y = (int)round(X.y);
    SDL_BlitSurface(source, NULL, destination, &offset);
}

void draw_rect(int x, int y, int w, int h, int R, int G, int B, SDL_Surface* dest)
{
    SDL_Rect r = {x, y, w, h};
    SDL_FillRect(dest, &r, SDL_MapRGB(screen->format, R, G, B));
}

#endif
