#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_short("Street in Seneca");
   set_long(
@DESC
This street leads from the east-west crossroad to the road that
circles the city. Made from cobblestone, the stone surface has 
stood up to a lot of wear. To the east, you can see into the 
yard in front of the %^CYAN%^Weapon Shop%^RESET%^. Just to the south, this street 
reaches the road that circles the city. 
DESC
   );
   set_items(([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "south" : "/d/attaya/seneca/road22",
      "north" : "/d/attaya/seneca/street11",
      "east" : "/d/attaya/seneca/weaponyard"
   ]) );
}
