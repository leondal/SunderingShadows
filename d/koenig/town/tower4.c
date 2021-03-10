#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Bare Room");
  set_long("%^BOLD%^%^WHITE%^There isn't much to see on these lower floors but you do "
           "notice that they appear to be used often. The %^RESET%^floor%^BOLD%^%^WHITE%^ looks well "
           "traveled, and the %^RESET%^walls%^BOLD%^%^WHITE%^ are very bare. Looking around it gives "
           "you a feeling of %^RESET%^coldness%^BOLD%^...%^RESET%^\n");
  set_smell("default", "You can almost NOT smell the dungeons now.");
  set_listen("default", "You can hear movement ahead and someone shouting from above.");
  set_exits( ([
     "east" : "/d/koenig/town/tower3",
     "west" : "/d/koenig/town/tower5"
]) );
}
