// Hallway of Asgard Keep ~Circe~ 8/14/15
#include <std.h>
#include "/d/laerad/laerad.h"

inherit STORAGE"hallway.c";

void create(){
   ::create();
   set_long(::query_long()+"This section of the hallway is often crowded "
      "with people using the %^BOLD%^%^BLACK%^gate%^RESET%^ to the south, "
      "travelling deeper into the keep to the north, or visiting the "
      "%^ORANGE%^shops %^RESET%^along the western branch.\n");
   set_exits(([
      "west" : KEEP"hallway2",
      "south" : KEEP"gate",
      "north" : KEEP"hallway5"
   ]));
   add_item("gate","The gateway to the south passed through the wall, "
      "granting access to the island. Security is a priority here on Laerad, "
      "as evidenced by the murderholes you can see in the ceiling between "
      "the two iron gates.");
}

/*
Guards and/or citizens to be added later.
void reset(){
  ::reset();
  if(!present("Seneca Guard 2"))
     new("/d/attaya/newseneca/mon/city_guard")->move(TO);
  if(!present("psion"))
     new("/d/attaya/newseneca/mon/psi_guard")->move(TO);
}
*/