#include <std.h>
#include "../shadow.h"
inherit INHDIR+"path";

void create(){ 
   ::create();
   set_long("%^BOLD%^Rough path%^RESET%^\n"
"This small foot-trail could barely be called even that.  It's nothing more than a %^ORANGE%^worn path%^RESET%^"
" where numerous feet have obviously trodden their way through the %^GREEN%^forest%^RESET%^, avoiding the inner"
" roads of Shadow city.  The %^BLACK%^%^BOLD%^stone walls%^RESET%^ of the city rises far above you, topped with"
" patrolling guards and archers that keep a vigilant watch over this area.  Upon the other side, a%^GREEN%^"
" great forest %^RESET%^borders the trail, so thickly grown that there's no visible way to leave the path and "
"enter it.\n");
   set("night long","%^BOLD%^Rough path%^RESET%^\n"
"This small foot-trail could barely be called even that.  It's nothing more than a %^ORANGE%^worn path%^RESET%^"
" where numerous feet have obviously trodden their way through the %^GREEN%^forest%^RESET%^, avoiding the inner"
" roads of Shadow city.  The %^BLACK%^%^BOLD%^stone walls%^RESET%^ of the city rises far above you like a "
"%^BLACK%^%^BOLD%^towering shadow%^RESET%^ in the night, topped with patrolling guards and archers that keep a "
"vigilant watch over this area.  Upon the other side, a %^GREEN%^great forest %^RESET%^borders the trail, so "
"%^BLUE%^dark %^RESET%^and thickly grown that there's no visible way to leave the path and enter it.\n");
   set_exits(([
     "north":VILLAGEDIR"path4",
     "south":VILLAGEDIR"path6",
   ]));
}
