#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit BEACHBASE;

void create() {
  ::create();
  set_long(query_long() + "  Further to the south,%^BOLD%^%^BLACK%^"
    +"rocky cliffs%^RESET%^ extend to the sea, blocking off further"
    +" travel in that direction.");
  add_item(({"cliffs", "cliff", "rocky cliffs", "rocky cliff"}), "A"
    +" little further to the south, a line of%^BOLD%^%^BLACK%^ black"
    +" rocked cliffs%^RESET%^ extend into the sea. The"
    +" %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
    +"%^GREEN%^l%^BOLD%^e %^RESET%^is dense at the top, making"
    +" travelling in that direction unfeasible.");
  set_exits( ([ "southeast" : ROOMS + "beach04",
                "northeast" : ROOMS + "beach02"]) );
}


