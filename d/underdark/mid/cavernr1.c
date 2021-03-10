#include <std.h>
#include "../defs.h"
inherit INH+"cavern";

void create(){ 
   ::create();
   set_long("%^BLUE%^A vast limestone cavern%^RESET%^\n"+ ::query_long() +"%^CYAN%^  Discarded %^ORANGE%^rubble"
"%^CYAN%^ lies against the walls here, at the entrance to a small side-cavern southeast of here.%^RESET%^\n");
   add_item(({"pile","rubble"}),"%^CYAN%^Small piles of discarded %^ORANGE%^rubble%^CYAN%^ are heaped up "
"against the walls, by the entry to a smaller cavern just to the southwest.  It seems like the rubble has been "
"freshly moved, and may once have been blocking the way into the small side alcove.%^RESET%^");
   set_exits(([
     "west":MID"cavernq1",
     "northwest":MID"cavernq2",
     "north":MID"cavernr2",
     "southeast":MID"portal1",
   ]));
}

