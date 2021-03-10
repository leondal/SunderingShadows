#include <std.h>
#include "../defs.h"
inherit INH+"path";

void create(){ 
   ::create();
   set_long("%^BOLD%^Roughly hewn trail%^RESET%^\n"
"This %^ORANGE%^rough trail%^RESET%^ could barely even be called that.  It's nothing more than a "
"well-trodden path through the surrounding %^GREEN%^forest%^RESET%^, where the plants and trees have been "
"either carelessly crushed underfoot, or pushed aside by something quite large.  The remains of several "
"trees line either side of the trail, most snapped and broken to allow passage to whatever passes through "
"here.  Around you rises the rest of the forest, though it's strangely %^CYAN%^silent%^RESET%^ of the usual "
"sounds of birds and insects.  Above you to the north looms a great mountain range, casting %^BLUE%^shadows "
"%^RESET%^over the treetops further upward.\n");
   set("night long","%^BOLD%^Roughly hewn trail%^RESET%^\n"
"This %^ORANGE%^rough trail%^RESET%^ could barely even be called that.  It's nothing more than a "
"well-trodden path through the surrounding %^GREEN%^forest%^RESET%^, where the plants and trees have been "
"either carelessly crushed underfoot, or pushed aside by something quite large.  The remains of several "
"trees line either side of the trail, most snapped and broken to allow passage to whatever passes through "
"here.  Around you rises the rest of the forest, though it's strangely %^CYAN%^silent%^RESET%^ of the usual "
"sounds of birds and insects.  Above you to the north looms a great mountain range, a %^BLUE%^dark shadow "
"%^RESET%^against the even darker backdrop of night sky.\n");

   set_exits(([
     "northeast":ROOMS"path3",
     "southwest":ROOMS"path1",
   ]));
}
