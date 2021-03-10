#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("light",1);
  set_property("indoors",1);
  set_short("Warehouse");
  set_long(
@VILLAGE
%^ORANGE%^Warehouse%^RESET%^
You have entered a very large warehouse that is kept clean
and ready for merchants passing through the village. In one
far corner you can see comfortable bunk beds set up for
the merchants comfort.
VILLAGE
  );
  set_smell("default","Despite the cleanliness it is musty.");
  set_listen("default","A mouse or two scurries across the vast the floor.");
  set_items(([
     "beds" : "They are of good size and look relatively comfortable. They are kept for the merchants who pass through here."
  ]) );
  set_exits( ([
     "out" : "/d/darkwood/forest/village/str9"
  ]) );
}
