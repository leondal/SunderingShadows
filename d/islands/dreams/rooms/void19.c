#include "../defs.h"
inherit VOID;

void create()
{
  ::create();
  set_exits(
    ([
    "north" : ROOMS+"void15",
    "south" : ROOMS+"void23",
    "east" : ROOMS+"void20",
    "west" : ROOMS+"void18",
    "up" : ROOMS+"void7",
    "down" : ROOMS+"void31"
    ]) );
  switch(random(6))
  {
  case 0:
    remove_exit("north");
    break;
  case 1:
    remove_exit("south");
    break;
  case 2:
    remove_exit("east");
    break;
  case 3:
    remove_exit("west");
    break;
  case 4:
    remove_exit("up");
    break;
  case 5:
    remove_exit("down");
    break;
  }
}