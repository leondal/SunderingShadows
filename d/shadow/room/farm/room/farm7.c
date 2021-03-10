#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_long(::query_long()+"\nThe %^GREEN%^farmyard %^RESET%^"+
      "comes to an end to the west here, with the %^BOLD%^"+
      "%^BLUE%^stream %^RESET%^at the bottom of the cliff.  "+
      "The yard opens back up to the east.\n");
   set_exits(([
      "north" : PATHS"farm4",
      "northeast" : PATHS"farm5",
      "east" : PATHS"farm8",
      "southeast" : PATHS"farm12",
      "south" : PATHS"farm11"
   ]));
   add_item(({"stream","cliff"}),"The cliff drops sharply to the "+
      "west.  The stream bubbles down below after dropping from the "+
      "falls to the northwest.");
}