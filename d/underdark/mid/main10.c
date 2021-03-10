#include <std.h>
#include "../defs.h"
inherit INH+"main";

void create(){ 
   ::create();
   set_long("%^BLUE%^A broad underground tunnel%^RESET%^\n"+ ::query_long() +
"\n");
   set_exits(([
     "east":MID"main11",
     "west":MID"main09",
   ]));
}
