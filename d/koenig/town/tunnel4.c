#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Secret Passage");
  set_long("%^BOLD%^%^BLUE%^This tunnel seems to be endless, and you're beginning to wonder where the end of it is. Maybe the end is just up ahead. Then again, maybe not. %^RESET%^%^BLUE%^Tread carefully...%^RESET%^\n");
  set_smell("default", "You smell damp earth surrounding you.");
  set_listen("default", "You hear the braces groan with their weight.");
  set_exits( ([
     "southeast" : "/d/koenig/town/tunnel3",
     "north" : "/d/koenig/town/tunnel5"
]) );
}
void init()
{
  ::init();
do_random_encounters( ({"/d/koenig/town/items/boulder"}),50,5);
}
