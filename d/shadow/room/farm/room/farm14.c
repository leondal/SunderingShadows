#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_long(::query_long()+"\nThe %^GREEN%^grass %^RESET%^seems "+
      "to get taller to the south, blocking your view that way.  "+
      "The %^CYAN%^farmhouse %^RESET%^itself is just north of here.\n");
   set_exits(([
      "west" : PATHS"farm13",
      "northwest" : PATHS"farm9",
      "north" : PATHS"farm10",
      "east" : PATHS"farm15"
   ]));
}