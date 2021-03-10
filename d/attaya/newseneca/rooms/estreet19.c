//estreet19 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LILA;

void create(){
   ::create();
   set_long(::query_long()+"To the west, you see the side of a "+
      "%^BOLD%^building %^RESET%^trimmed in %^BOLD%^%^BLUE%^blue"+
      "%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"estreet18",
      "south" : ROOMS"estreet20"
   ]));
   add_item("building","The building is painted mostly white and "+
      "is trimmed in blue.  You do not see any windows on this "+
      "side, and it is difficult to tell what the building might be.  "+
      "To the south is the back of the building, while it continues "+
      "northward all the way to Viento Lane.");
}