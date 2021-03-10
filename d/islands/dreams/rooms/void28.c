#include "../defs.h"
inherit VOID;

void create()
{
  ::create();
  set_exits(
    ([
    "north" : ROOMS+"void36",
    "south" : ROOMS+"void32",
    "east" : ROOMS+"void25",
    "west" : ROOMS+"void27",
    "up" : ROOMS+"void16",
    "down" : ROOMS+"void4"
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

void reset()
{
  ::reset();
  if(!present("comadon"))
  {
    new(MON+"comadon")->move(this_object());
  }
}
