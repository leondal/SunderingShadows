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
You are entering the part of Seneca that has withstood 
attacks over time. Here the buildings have been rebuilt 
where destroyed, and you can see the differences in the 
structure where parts have been rebuilt. To the east you 
see the local %^CYAN%^Hospital%^RESET%^, and to the west is the local %^CYAN%^Bank%^RESET%^.
DESC
   );
   set_items( ([
      "buildings" : "You can see where the buildings have been destroyed and rebuilt.",
   ]) );
   set_exits( ([
      "north" : "/d/attaya/seneca/street1",
      "south" : "/d/attaya/seneca/street3",
      "east" : "/d/attaya/seneca/healyard",
      "west" : "/d/attaya/seneca/bankyard",
   ]) );
}
