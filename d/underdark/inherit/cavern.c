#include <std.h>
#include "../defs.h"
inherit CROOM;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   if(!random(4)) set_property("no teleport",1);
   set_terrain(NAT_CAVE);
   set_travel(PAVED_ROAD);
   set_name("A vast limestone cavern");
   set_short("%^BLUE%^A vast limestone cavern%^RESET%^");
   set_long("%^CYAN%^This massive %^WHITE%^limestone cavern %^CYAN%^seems far longer than wide.  You can "
"easily see from the northern wall to the south, but the east to west is another matter entirely, as the "
"distant wall is lost in the %^BOLD%^%^BLACK%^blackness %^RESET%^%^CYAN%^of the underdark.  The air is filled "
"with %^BLUE%^moisture %^CYAN%^and what at first appear to be motes of dust, floating all around.  Only a "
"moment's observation, however, reveals them to be %^ORANGE%^tiny spores %^CYAN%^from the myriad of mushrooms "
"and fungi that fill the cavern, coating the floor and climbing any available stone surface.  Taking even a "
"few steps in any direction is difficult, as much for the numerous mushrooms as for the stalagmites that dot "
"the floor in all directions.  Above you hang the tapered points of countless stalactites, reaching down from "
"the %^BOLD%^%^BLACK%^shadow-swept %^RESET%^%^CYAN%^ceiling toward their counterparts on the floor below."
"%^RESET%^");
   set_smell("default","Thick, cloying spores are suspended in the air all around you.");
   set_listen("default","From somewhere in the distance comes the drip, drip of water.");
   set_items(([
     ({"walls","roof","ceiling","floor","rock","stone"}):"%^CYAN%^The walls enclosing this cavern are all "
"formed of %^WHITE%^pale limestone%^CYAN%^.  Stalactites protrude from the %^BOLD%^%^BLACK%^shadowed roof "
"%^RESET%^%^CYAN%^above, dripping %^BLUE%^moisture %^CYAN%^around the stalagmites that dot the stone floor."
"%^RESET%^",
     ({"motes","dust","spores"}):"%^CYAN%^The air is filled with what at first appear to be tiny motes of "
"dust, barely propelled through the air for a lack of %^BOLD%^breeze%^RESET%^%^CYAN%^.  A closer look reveals "
"the floating particles to be %^ORANGE%^tiny spores%^CYAN%^, probably from the numerous %^WHITE%^mushrooms "
"%^CYAN%^that litter the ground of the cavern.%^RESET%^",
     ({"stalagmites","stalactites"}):"%^CYAN%^From the %^BOLD%^%^BLACK%^shadowed %^RESET%^%^CYAN%^ceiling "
"above hang the tapered points of numerous stalactites.  They reach down toward their stalagmite counterparts "
"on the floor below, dripping %^BLUE%^moisture %^CYAN%^onto the stone ground.%^RESET%^",
     ({"mushrooms","fungi"}):"%^CYAN%^A myriad of %^WHITE%^mushrooms %^CYAN%^and %^GREEN%^fungi %^CYAN%^of all "
"kinds litter the floor, obviously thriving in this damp cave.  Wherever you look, you can see them coating "
"the stone floor, and growing up and over the stalagmites and walls.%^RESET%^",
   ]));
}
