#include <std.h>
#include "short.h"

inherit CITYIN;

void create() {
   ::create();
   set_short("front yard");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",3);
   set_long(
@DESC
This is a small cobblestone path that leads to the facade 
of a small building. A yard of green grass surrounds the 
path.
DESC
   );
   set_exits(([
      "enter" : "/d/attaya/seneca/pawnshop",
      "south" : "/d/attaya/seneca/street5",
      "west" : "/d/attaya/seneca/street3",
   ]));
   set_door("door", "/d/attaya/seneca/pawnshop", "enter", 0);
   set_open("door", 0);
   set_items(([
      "path" : "It is a small cobblestone path.",
      "grass" : "The health green grass has been recently cut.",
   ]));
}
