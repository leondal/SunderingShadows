#include "../defs.h"
inherit VOID;

void create()
{
  ::create();
  set_exits(
    ([
    "north" : ROOMS+"void32",
    "south" : ROOMS+"void28",
    "east" : ROOMS+"void33",
    "west" : ROOMS+"void35",
    "up" : ROOMS+"void24",
    "down" : ROOMS+"void12"
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