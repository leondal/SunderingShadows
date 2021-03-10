#include <std.h>
#include "short.h"

inherit CITYIN;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_short("Outside the Adventurers' Hall.");
   set_property("indoors",0);
   set_property("light",2);
   set_long(
@DESC
This is a large stone courtyard outside the %^CYAN%^Adventurers' Hall%^RESET%^ 
of Seneca. Stones of varying colors make a pattern on the ground.  
A few small round bushes grow like a fence around the courtyard.
The %^CYAN%^Adventurers' Hall%^RESET%^ is a large stone building of simple 
construction. The roof forms overhangs on all four walls and there 
are no curves used at all.
DESC
   );
   set_exits(([
      "enter" : "/d/attaya/seneca/adv_hall",
      "east" : "/d/attaya/seneca/street4",
      "north" : "/d/attaya/seneca/street7",
      "west" : "/d/attaya/seneca/street9"
   ]));
   set_door("door", "/d/attaya/seneca/adv_hall", "enter", 0);
   set_open("door", 0);
   "/d/attaya/seneca/adv_hall"->set_open("door",0);
   set_items(([
      "path" : "It is a small cobblestone path.",
      "grass" : "The healthy green grass has been recently cut.",
   ]));


}
