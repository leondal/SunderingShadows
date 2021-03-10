#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_property("light", 2);
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_short("Street in Seneca");
   set_long(
@DESC
This street leads from the east-west crossroad to the road that
circles the city. Made from cobblestone, the stone surface has 
stood up to a lot of wear. To the east, you can see into the 
yard surrounding the great cathedral. To the west, you hear a
great deal of noise coming from the %^CYAN%^Trainer%^RESET%^. A little way to 
the south, the street reaches the road that circles the city. 
DESC
   );
   set_items(([
      "cobblestones" : "These are cobblestones.",
   ]) );
   set_exits( ([
      "south" : "/d/attaya/seneca/street12",
      "north" : "/d/attaya/seneca/street10",
      "west" : "/d/attaya/seneca/trainer"
   ]) );
}
