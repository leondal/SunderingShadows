#include <std.h>
#include "short.h"

inherit CITYIN;

void create() {
   ::create();
   set_short("front yard");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",2);
   set_long(
@DESC
You are climbing a large staircase leading to the entrance to 
the %^CYAN%^Questing Hall%^RESET%^. The trees surrounding this staircase are 
sculpted to resemble lions leaping towards you. The walls of 
the building are smooth red marble with large stained glass 
windows everywhere. The windows reflect the clouds above as 
does the shiny marble in places. The vivid colors starkly 
contrast the lush green yard around you.
DESC
   );
   set_exits(([
      "enter" : "/d/attaya/seneca/questhall",
      "west" : "/d/attaya/seneca/street4",
      "north" : "/d/attaya/seneca/street5",
   ]));
   set_door("door", "/d/attaya/seneca/questhall", "enter");
   set_open("door", 1);
   set_items(([
      "path" : "It is a small cobblestone path.",
      "grass" : "The healthy green grass has been recently cut.",
   ]));
}
