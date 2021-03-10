//forest175
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
      set_long("%^GREEN%^You are walking through a thick forest"
" whose dense canopy allows only a few rays of %^RESET%^surreal"
" light %^GREEN%^through, creating an almost magical presence"
" around you. The underbrush is thick and full of life here,"
" as ivy climbs the trees in abundance and ferns seem to reach"
" out towards one another, their delicate and lacy leaves"
" brushing against everything around them.  You can just make out"
" what looks to be a road through the trees to the north.%^RESET%^\n");
      set("night long","%^RESET%^%^GREEN%^You've wandered into "
" the Yntala Forest. Very little %^RESET%^moonlight"
" %^GREEN%^makes it's way through the dense"
" canopy above, giving this forest a very %^RESET%^surreal"
" %^RESET%^feeling. %^GREEN%^Crickets chirp from somewhere in"
" the thick underbrush, and %^BOLD%^%^BLACK%^shadows"
" %^RESET%^%^GREEN%^dance around you, creating the illusion"
" of movement even when there is none.%^RESET%^\n");

set_exits(([
"south":INRMS+"forest176",
"north":"/d/darkwood/tabor/road/road6",
"east":INRMS+"forest173"
]));
}