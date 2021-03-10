#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("Outside the Great Hall");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",2);
   set_long(
@DESC
This is a stone courtyard outside the %^CYAN%^Great Hall%^RESET%^ of 
Seneca.  A row of trees and a small stone wall separates 
this yard from that of the house to the north.  The large
L-shaped building has doorways to the east and south.  It doesn't
appears the hall has fallen into disuse and there isn't much
activity around it.
DESC
   );
   set_exits(([
      "south" : "/d/attaya/seneca/hall_main",
      "west" : "/d/attaya/seneca/hall_announce",
      "east" : "/d/attaya/seneca/street9"
   ]));
   set_items(([
      "path" : "It is a small cobblestone path.",
      "grass" : "The healthy green grass has been recently cut.",
   ]));

}
