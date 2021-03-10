#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_long(::query_long()+"\nThe %^CYAN%^farmhouse %^RESET%^is "+
      "directly west of here, its walls dotted with %^BOLD%^"+
      "portholes %^RESET%^in various shapes and heights.\n");
   set_exits(([
      "northeast" : PATHS"path2",
      "east" : PATHS"farm19",
      "southeast" : PATHS"farm17",
      "south" : PATHS"farm16",
      "southwest" : PATHS"farm15"
   ]));
}
