#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",1);
   set_property("indoors",1);
   set_terrain(BUILT_CAVE);
   set_travel(DIRT_ROAD);
   set_name("Underground tunnel");
   set_short("Underground tunnel");
   set_long("%^BOLD%^Underground tunnel%^RESET%^\n"
"This tunnel looks quite well built, probably the remains of some abandoned city infrastructure.  The walls "
"are made of %^BLACK%^%^BOLD%^stone and mortar%^RESET%^, and look quite sturdy.  They're a little damp, "
"however, as though %^CYAN%^water%^RESET%^ is leaking from somewhere above, running down the walls.  The "
"tunnel continues southward into the %^BLUE%^cavern's shadows%^RESET%^, while above you rests a heavy grate, "
"secured between the stones of the roof above.  It seems to offer the only way out of here.\n");
   set_smell("default","A faint smell of dampness permeates the air around you.");
   set_listen("default","It's particularly quiet here, except for an occasional drip of water.");

   set_items(([
     ({"cavern","walls","roof","stone"}):"The %^BLACK%^%^BOLD%^stone-and-mortar%^RESET%^ walls look quite "
"sturdy, though they're a little damp, as though %^CYAN%^water%^RESET%^ is leaking from somewhere above.",
     "grate":"The grate above you is old and %^ORANGE%^rusted%^RESET%^, and looks quite heavy.  It has been "
"left open to reveal the single way out of here."
    ]));

   set_exits(([
     "up":COVE"thief2",
     "south":COVE"thief4"
   ]));
}
