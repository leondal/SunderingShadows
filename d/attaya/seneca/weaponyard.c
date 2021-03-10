#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("Outside the Weapon Shop");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",2);
   set_long(
@DESC
You are outside a building. There is a sign on the door that
reads "Future home of the %^CYAN%^Seneca Weapon Shop%^RESET%^".
DESC
   );
   set_exits(([
      "enter" : "/d/attaya/seneca/weaponshop",
      "west" : "/d/attaya/seneca/street12",
      "south" : "/d/attaya/seneca/road21"
   ]));
   set_items(([
      "path" : "It is a small cobblestone path.",
      "grass" : "The healthy green grass has been recently cut.",
   ]));

}
