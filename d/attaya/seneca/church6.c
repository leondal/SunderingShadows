#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("Bell tower");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_long(
@DESC
You are on a staircase inside the %^CYAN%^Cathedral of Seneca%^RESET%^. The stairs 
wind around the interior of the bell tower and grant access to 
the bells within it.
DESC
   );
   set_exits(([
      "up":"/d/attaya/seneca/church7",
      "down":"/d/attaya/seneca/church5",
   ]));
   set_items(([
      "bells" : "The bells are enormous and made of brass, they hang into this room from a heavy rod about a hundred feet above you.",
      "stairs" : "The stairs are made from wood planks and bound by metal wire.  An iron railing gives you some security.",
      "staircase" : "The stairs are made from wood planks and bound by metal wire.  An iron railing gives you some security.",
   ]));
}
