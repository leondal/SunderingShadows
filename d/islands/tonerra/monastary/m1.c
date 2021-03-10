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
%^RESET%^%^GREEN%^You are suddenly standing in an %^ORANGE%^open plain%^GREEN%^. The openness around
you surprises you. It almost daring you to advance further
onto the plain. There seems to be no choice but to go forward.%^RESET%^
OLI
   );
   set_smell("default","The smells of green grass and some thistle greet you.");
   set_listen("default","The wind blows lightly by. In the distance you hear a grunt.");
   set_exits(([
      "west":MONASTERY+"m5",
      ]));
}

