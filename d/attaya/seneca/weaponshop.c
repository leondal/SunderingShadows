#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   object ob;

   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("light", 2);
   set_property("indoors", 1);
   set_short("Seneca Weapon Shop");
   set_long(
@DESC
You have entered an empty store. There is a sign on a table 
that reads "Future home of the %^CYAN%^Seneca Weapon Shop%^RESET%^".
DESC
   );
   set_exits( ([
      "out" : "/d/attaya/seneca/weaponyard"
   ]) );
}

