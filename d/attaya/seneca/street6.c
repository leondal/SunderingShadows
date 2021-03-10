#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_short("Street in Seneca");
/*   set_long(
@DESC
This is the crossroad through Seneca, travelling east and west.  
Made from cobblestone, the stone surface has stood up to a lot 
of wear. To the south is the entrance to the %^CYAN%^Armor Shop%^RESET%^. To the
east you see a great %^CYAN%^Coliseum%^RESET%^. A street leads off toward the 
northeast.
DESC
   );
*/
   set_long(
@DESC
This is the crossroad through Seneca, travelling east and west.  
Made from cobblestone, the stone surface has stood up to a lot 
of wear. To the east you see a most unusual 
sight.  A cloud of %^CYAN%^mist %^RESET%^rises from the ground, drifting
upward from the %^BOLD%^broken rubble %^RESET%^of the old arena.  Yet, 
through the mist, appearing to drift in and out of existence is
the grand, imposing form of a circular, proud%^BOLD%^ stone structure 
%^RESET%^with shield-shaped pennants in %^BOLD%^%^BLUE%^blue %^RESET%^bordered with %^BOLD%^%^RED%^red
%^RESET%^snapping in the wind all along the building's top.
A street leads off toward the northeast.
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
//      "east" : "/d/attaya/seneca/arenayard",
      "south" : "/d/attaya/seneca/armoryard",
      "west" : "/d/attaya/seneca/street5",
      "northeast" : "/d/attaya/seneca/street13"
   ]) );
}
