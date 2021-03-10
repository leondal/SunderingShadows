#include <std.h>
#include "../defs.h"
inherit INH+"shaft";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^\n"+ ::query_long() +"%^ORANGE%^  It seems as "
"though this section of the tunnels have been recently mined, as several piles of %^WHITE%^raw stone "
"%^ORANGE%^are strewn about the ground.  The shaft travels upwards from this dead-end toward the "
"northeast, curving around to the left out of sight.%^RESET%^\n");
   set_exits(([
     "northeast":MINES"shaft3c",
   ]));
}
