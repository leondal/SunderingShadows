#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Dark Room Far Beneath the Crypt");
  set_long("%^BOLD%^%^BLACK%^Well there are only two directions to go here. Either back the way you came, or down. Which shall you choose?%^RESET%^\n");
  set_exits( ([
     "north" : "/d/koenig/town/crypt14.c",
     "down" : "/d/koenig/town/crypt18.c"
]) );
}
