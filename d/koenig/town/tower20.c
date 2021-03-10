#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Dirty Room");
  set_long("%^BOLD%^%^WHITE%^There is something very odd about this floor of the tower. It appears there "+
"are no other exits but the one through which you entered. You also notice that "+
"the %^RESET%^floor%^BOLD%^%^WHITE%^ is covered in %^RESET%^%^ORANGE%^dirt%^BOLD%^%^WHITE%^ and %^RESET%^%^GREEN%^grime%^BOLD%^%^WHITE%^.%^RESET%^\n");
  set_smell("default", "It smells of dirt and grime... yuck.");
  set_listen("default", "You hear the dirt and grime grind beneath your boots as you walk across the floor.");
  set_items( ([
     "floor" : "You notice that there are other footprints here other then your own.",
     "footprints" : "The other set of footprints appear to be heading north."
]) );
  set_exits( ([
     "east" : "/d/koenig/town/tower19",
     "north" : "/d/koenig/town/tower21.c"
]) );
  set_invis_exits( ({"north"}) );
}
