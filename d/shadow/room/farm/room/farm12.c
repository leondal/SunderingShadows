#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_long(::query_long()+"\nThe %^GREEN%^grass %^RESET%^seems "+
      "to get taller to the east, blocking your view that way.  "+
      "The %^GREEN%^farmyard %^RESET%^itself opens up to the north.\n");
   set_exits(([
      "northwest" : PATHS"farm7",
      "north" : PATHS"farm8",
      "northeast" : PATHS"farm9",
      "east" : PATHS"farm13",
      "west" : PATHS"farm11"
   ]));
}