// Hallway of Asgard Keep ~Circe~ 8/14/15
#include <std.h>
#include "/d/laerad/laerad.h"

inherit STORAGE"hallway.c";

void create(){
   ::create();
   set_long(::query_long()+"The main hallway lies to the east, while the "
      "shop to the north bears a %^ORANGE%^sign %^RESET%^with a "
      "%^BOLD%^needle%^RESET%^ and %^CYAN%^thread%^RESET%^.\n");
   set_exits(([
      "east" : KEEP"hallway1",
      "north" : KEEP"tailor",
      "west" : KEEP"hallway3"
   ]));
   add_item(({"sign","shop"}), "To the north is a small shop filled with "
      "stacks of fabric and racks of completed clothes for sale. The sign "
      "bears no words but features a spool of %^CYAN%^thread %^RESET%^topped "
      "by a %^BOLD%^needle%^RESET%^.");
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