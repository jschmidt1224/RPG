#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include "init.h"
#include "timer.h"
#include "Rectangle.h"
#include "sprite.h"
#include "character.h"
#include "local.h"
#include "socket.h"



SDL_Surface* screen;
SDL_Event event;

int main(int argc, char* args[])
{
  bool quit;
  if (init(480, 640, 32))
    return 1;

  Timer delta;
  Socket sock;
  WSADATA wsaData;
  struct sockaddr_in serverAddr;
  memset(&serverAddr, 0, sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_addr.s_addr = inet_addr("10.18.201.218");
  serverAddr.sin_port = htons(12345);
  if (WSAStartup(MAKEWORD(2, 0), &wsaData) != 0)
  {
    exit(1);
  }

  if(sock.bindSocket(0) < 0)
  {
    exit(WSAGetLastError());
  }

  sock.sendMessage(&serverAddr, "RPGCJason");


  Rect rect = {50, 50, 32, 32};
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
    //SDL_Delay(10);
  }

  return 0;
}
