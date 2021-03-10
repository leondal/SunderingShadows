#include <std.h>
#include "../defs.h"
inherit INH+"tunnel";

void create(){ 
   ::create();
   set_long("%^BOLD%^%^BLACK%^A broad mining tunnel%^RESET%^\n"
+ ::query_long() +"  The tunnel continues toward the southeast, while a side "
"tunnel branches away into darkness.  Further north, you can see "
"%^BOLD%^%^WHITE%^light %^RESET%^filtering in from the wide tunnel mouth "
"that leads outside.\n");
   set_exits(([
     "north":MINES"mines1",
     "southeast":MINES"mines3",
     "southwest":MINES"shaft2a",
   ]));
}
