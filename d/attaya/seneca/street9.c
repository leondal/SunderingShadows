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
stood up to a lot of wear. A large L-shaped building is to the
southwest, the yard is to the west. To the south, the street 
passes a few more buildings and yards. The entrance to the 
%^CYAN%^Adventurers' Hall%^RESET%^ is to the east.
DESC
   );
   set_items(([
      "cobblestones" : "These are cobblestones.",
      "buildings" : "There is an L-shaped building to the west and a few other buildings along the road."
   ]) );
   set_exits( ([
      "east" : "/d/attaya/seneca/advyard",
      "west" : "/d/attaya/seneca/hallyard",
      "south" : "/d/attaya/seneca/street10",
      "north" : "/d/attaya/seneca/street8"
   ]) );
}
