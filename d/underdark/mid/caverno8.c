#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"%^CYAN%^  Within the northern wall "
"of the cavern, a %^BOLD%^%^BLACK%^small dark hole %^RESET%^%^CYAN%^opens onto a tunnel beyond.%^RESET%^\n");
   add_item(({"hole","tunnel"}),"%^CYAN%^From within the northern cavern wall here opens a "
"%^BOLD%^%^BLACK%^small dark hole%^RESET%^%^CYAN%^, leading into what appears to be a tunnel beyond.%^RESET%^");
   set_exits(([
     "southwest":MID"cavernn7",
     "south":MID"caverno7",
     "southeast":MID"cavernp7",
     "tunnel":"/d/dagger/kinaro/mines/lower2q",
   ]));
}
