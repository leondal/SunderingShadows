#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",1);
   set_property("indoors",0);
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
   set_name("Roughly hewn trail");
   set_short("Roughly hewn trail");
   set_smell("default","A slight odor of decay taints the forest air around you.");
   set_listen("default","The forest around you is strangely quiet.");

   set_items(([
     ({"path","pathway","trail","rough trail"}):"The trail beneath your feet is barely even that; it's "
"nothing more than a trodden path through the forest, leading toward the mountain.  Trees and bushes have "
"been crushed or forced aside, by whatever travels up this way.",
     ({"forest","trees","bushes","plants"}):"The boughs of the forest surround you on either side.  The path "
"itself is formed of crushed undergrowth, and the remains of broken trees line either side of it.",
     ({"mountains","mountain range"}) : (:TO,"mountain_desc":)
   ]));
}

string mountain_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("Northward looms a great mountain range, rising above you like a %^BLUE%^dark shadow%^RESET%^ "
"against the darker backdrop of sky.");
   }
   return("Northward looms a great mountain range, casting shadows over you and blotting out much of the "
"sky.");
}
