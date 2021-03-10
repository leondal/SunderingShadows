#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("Akanar's Clothing Shop");
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",3);
   set_long(
@DESC
This large tent houses the %^CYAN%^Clothing Shop%^RESET%^. Bright colored 
clothing hangs from poles throughout the room. It is quite 
warm in here. In the center of the room is a round marble 
table where transactions are made.
DESC
   );
   set_listen("default", "The sides of the tent curl in the wind outside.");
   set_exits(([
      "east" : "/d/attaya/seneca/clothyard",
   ]));
}

void reset() {
   ::reset(); 
   if(!present("akanar"))
      new("/d/attaya/seneca/mon/akanar")->move(TO);
}
