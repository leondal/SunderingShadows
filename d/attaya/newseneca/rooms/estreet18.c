//estreet18 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LILA;

void create(){
   ::create();
   set_long(::query_long()+"To the west, you see the side of a "+
      "%^BOLD%^building %^RESET%^trimmed in %^BOLD%^%^BLUE%^blue"+
      "%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"estreet17",
      "south" : ROOMS"estreet19"
   ]));
   add_item("building","The building is painted mostly white and "+
      "is trimmed in blue.  You do not see any windows on this "+
      "side, and it is difficult to tell what the building might be.  "+
      "The front of the building is to the north, and it continues "+
      "southward, clearly enclosing another room.");
}