#include <std.h>
#include <terrain.h>
#include "../wemic.h"
inherit BEACHBASE;

void create() {
  ::create();
  set_long(query_long() + "  %^BOLD%^%^BLACK%^Rocky cliffs%^RESET%^"
    +" extend to the sea south of here, blocking off travel in that"
    +" direction.");
  add_item(({"cliffs", "cliff", "rocky cliffs", "rocky cliff"}), "A"
    +" line of%^BOLD%^%^BLACK%^ black"
    +" rocked cliffs%^RESET%^ extend into the sea. The"
    +" %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^"
    +"%^GREEN%^l%^BOLD%^e %^RESET%^is dense at the top, making"
    +" travelling in that direction unfeasible.");
  set_exits( ([ "northwest" : ROOMS + "beach03"]) );
}


