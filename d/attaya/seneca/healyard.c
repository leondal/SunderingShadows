#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("outside the healer");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",3);
   set_long(
@DESC
You are at the stoop of a small %^CYAN%^Hospital%^RESET%^. It is adequate
for the needs of Seneca. The building is quite old and 
shows signs of a recent partial restoration. Stone figures 
and markings near the roof are ancient symbols that guard 
against evil.
DESC
   );
   set_exits(([
      "enter" : "/d/attaya/seneca/healer",
      "west" : "/d/attaya/seneca/street2",
      "north" : "/d/attaya/seneca/road1"
   ]));
   set_items(([
      "path" : "It is a small cobblestone path.",
      "grass" : "The healthy green grass has been recently cut.",
   ]));
}
