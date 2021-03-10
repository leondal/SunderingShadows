#include <std.h>
#include "../farm.h"

inherit BARNYARD;

void create(){
   ::create();
   set_long(::query_long()+"\nThe %^CYAN%^farmhouse %^RESET%^is "+
      "directly east of here, its walls dotted with %^BOLD%^"+
      "portholes %^RESET%^in various shapes and heights.\n");
   set_exits(([
      "northwest" : PATHS"farm6",
      "west" : PATHS"farm9",
      "southwest" : PATHS"farm13",
      "south" : PATHS"farm14",
      "southeast" : PATHS"farm15"
   ]));
}
