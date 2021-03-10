#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_short("Street in Seneca");
/*
   set_long(
@DESC
This is a street leading through Seneca. Several shops back to
this street on the west, and there is a large building to the
east. Made from cobblestone, the stone surface of the street has 
stood up to a lot of wear. To the south you see a great %^CYAN%^Coliseum%^RESET%^. 
A street leads off toward the southwest.
DESC
   );
*/
   set_long(
@DESC
This is a street leading through Seneca. Several shops back to
this street on the west, and there is a large building to the
east. Made from cobblestone, the stone surface of the street has 
stood up to a lot of wear. To the south you see a most unusual 
sight.  A cloud of %^CYAN%^mist %^RESET%^rises from the ground, drifting
upward from the %^BOLD%^broken rubble %^RESET%^of the old arena.  Yet, 
through the mist, appearing to drift in and out of existence is
the grand, imposing form of a circular, proud%^BOLD%^ stone structure 
%^RESET%^with shield-shaped pennants in %^BOLD%^%^BLUE%^blue %^RESET%^bordered with %^BOLD%^%^RED%^red
%^RESET%^snapping in the wind all along the building's top.  
A street leads off toward the southwest.
DESC
   );
   set_items( ([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
//      "south" : "/d/attaya/seneca/arenayard",
      "north" : "/d/attaya/seneca/street14",
      "southwest" : "/d/attaya/seneca/street6"
   ]) );
}
