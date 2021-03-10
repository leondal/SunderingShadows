//m1.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(GRASSLANDS);
   set_travel(FRESH_BLAZE);
   set_short("An open plain");
   set_property("light",2);
   set_property("no teleport",1);
   set_long(
@OLI
   %^BOLD%^%^GREEN%^An open plain%^RESET%^
%^RESET%^%^GREEN%^The plains spread out before you. In the distance you see something to
the west. The tall grass blows in the %^CYAN%^wind%^GREEN%^. Nothing could sneak up here
without detection. Nothing but a clean, straight fight could happen here.%^RESET%^
OLI
   );
   set_smell("default","The smells of green grass and some thistle greet you.");
   set_listen("default","The wind blows lightly by. In the distance you hear a grunt.");
   set_exits(([
      "east":MONASTERY+"m5",
      "west":MONASTERY+"m12",
      "north":MONASTERY+"m8",
      "south":MONASTERY+"m10",
      ]));
}

