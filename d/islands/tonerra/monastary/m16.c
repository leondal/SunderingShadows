//m1.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(SCRUB_LANDS);
   set_travel(GAME_TRACK);
   set_short("An open plain");
   set_property("light",2);
   set_property("no teleport",1);
   set_long(
@OLI
   %^BOLD%^%^GREEN%^An open plain%^RESET%^
%^BOLD%^%^GREEN%^The edge of the plain is here. A thick %^RESET%^%^GREEN%^unnatural forest%^BOLD%^%^GREEN%^ blocks any hope
of passage off the plain.%^RESET%^
OLI
   );
   set_smell("default","The smells of green grass and some thistle greet you.");
   set_listen("default","The wind blows lightly by. In the distance you hear a grunt.");
   set_exits(([


      "north":MONASTERY+"m15",
      "east":MONASTERY+"m11",

      ]));
}

