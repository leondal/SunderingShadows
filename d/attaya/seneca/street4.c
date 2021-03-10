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
Here is the end of the north-south stretch of road. There is a 
beautiful reflecting pool in the middle of the street, surrounded 
by a small rose garden. You stand in the shadow of the great 
%^CYAN%^Cathedral of Seneca%^RESET%^ to the south, the %^CYAN%^Questing Hall%^RESET%^ to the east, 
and the %^CYAN%^Adventurers' Hall%^RESET%^ to the west.
DESC
   );
   set_items( ([
      "buildings" : "You can see where the buildings have been destroyed and rebuilt.",
   ]) );
   set_exits( ([
      "north" : "/d/attaya/seneca/square",
      "south" : "/d/attaya/seneca/cathyard",
      "east":"/d/attaya/seneca/questyard",
      "west" : "/d/attaya/seneca/advyard",
   ]) );
}
