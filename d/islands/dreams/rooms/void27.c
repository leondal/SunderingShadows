#include "../defs.h"
inherit VOID;

void create()
{
  ::create();
  set_exits(
    ([
    "north" : ROOMS+"void35",
    "south" : ROOMS+"void31",
    "east" : ROOMS+"void28",
    "west" : ROOMS+"void26",
    "up" : ROOMS+"void15",
    "down" : ROOMS+"void3"
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