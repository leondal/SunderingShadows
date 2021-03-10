#include <std.h>
#include "../defs.h"
inherit VOID;

void create()
{
  ::create();
  set_exits(
    ([
    "north" : ROOMS+"void9",
    "south" : ROOMS+"void5",
    "east" : ROOMS+"void2",
    "west" : ROOMS+"void4",
    "up" : ROOMS+"void25",
    "down" : ROOMS+"void13"
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