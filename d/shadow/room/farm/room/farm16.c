#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_long(::query_long()+"\nThe %^GREEN%^grass %^RESET%^seems "+
      "to get taller to the south, blocking your view that way.  "+
      "A small stand of %^GREEN%^trees %^RESET%^is to the east, "+
      "and to the north you see a small %^ORANGE%^pathway%^RESET%^.\n");
   set_exits(([
      "west" : PATHS"farm15",
      "north" : PATHS"farm18",
      "northeast" : PATHS"farm19",
      "east" : PATHS"farm17"
   ]));
}