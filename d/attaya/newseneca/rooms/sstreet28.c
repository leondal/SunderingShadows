//sstreet28 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit VERDE;

void create(){
   ::create();
   set_long(::query_long()+"To the north, an impressive %^BOLD%^"+
      "bell tower %^RESET%^rises high overhead, while to the east, "+
      "you see the %^ORANGE%^junction %^RESET%^of %^GREEN%^Verde "+
      "Esplanade %^RESET%^and %^YELLOW%^Sol Boulevard%^RESET%^.\n");
   set_exits(([
      "east" : ROOMS"sstreet48",
      "west" : ROOMS"sstreet29"
   ]));
   add_item("bell tower","The bell tower of the cathedral to the "+
      "northwest towers over the city, casting a long shadow along "+
      "the road.  The bell is impossible to see from here, despite "+
      "the open archways you can see housing it.");
   add_item("tower","The bell tower of the cathedral to the "+
      "northwest towers over the city, casting a long shadow along "+
      "the road.  The bell is impossible to see from here, despite "+
      "the open archways you can see housing it.");
}