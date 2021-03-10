#include <std.h>
#include "../inherit/keep.h"
inherit CROOM;

void create() {
   set_monsters(({MONS+"halfogre"}),({1}));
   ::create();
   set_repop(60);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",2);
   set_name("Garden outside a ruined keep");
   set_short("%^GREEN%^Garden outside a ruined keep%^RESET%^");
   set_long("%^GREEN%^Garden outside a ruined keep%^RESET%^\n"
"%^GREEN%^Weeds %^RESET%^and %^BOLD%^%^GREEN%^vines %^RESET%^seem to have "
"had years to crawl all over this abandoned garden.  Cracked %^ORANGE%^"
"stones %^RESET%^shift underfoot, once perhaps the groundwork of a lovely "
"courtyard, but now just shattered fragments.  The stone %^BLUE%^walls "
"%^RESET%^are choked by greenery, crumbling slowly under their coils.  "
"Beyond them to the west rises the thick %^GREEN%^forest%^RESET%^, looming "
"up over the ruined keep beside you.  Entry to the keep seems to be to the "
"north, where the remains of a damaged %^MAGENTA%^bedroom %^RESET%^lie "
"partially exposed to the elements.\n");
   set_smell("default","The air is fresh and clean.");
   set_listen("default","You can hear the trill of birds from the forest beyond.");
   set_items(([
     ({"walls","weeds","vines","greenery","coils"}) : "%^GREEN%^Long ages "
"of abandonment seem to have allowed the walls to fall into a state of "
"disrepair.  Tendrils of plantlife crawl all over them, slowly breaking "
"down the stone beneath their grasp.%^RESET%^",
     ({"stones","groundwork"}) : "%^ORANGE%^Once perhaps the basis for a "
"lovely courtyard, the stones beneath your feet now form nothing but a "
"layer of cracked, ruined groundwork.%^RESET%^",
     "forest" : "%^GREEN%^To the west, the eaves of the forest rise up "
"towards the sky, looming over the keep.%^RESET%^",
     ({"keep","bedroom"}) : "%^MAGENTA%^The sprawling ruins of a keep lie "
"to the east.  Access seems to be through the ruined remnants of a bedroom "
"to the north, where most of the ceiling seems to have collapsed, and some "
"of the walls.%^RESET%^",
   ]));
   set_exits(([
     "north" : ROOMS"halfogre1",
   ]));
}
