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
%^RESET%^%^GREEN%^Here, behind the statue, the area seems quieter. The world seems
to %^RESET%^shimmer%^GREEN%^. The %^BOLD%^forest%^RESET%^%^GREEN%^ doesn't seem as imposing. The light flickers strangely.
OLI
   );
   set_items(([
   "forest":"The forest to the west almost seems unreal.",
   ]));
   set_smell("default","The smells of green grass and some thistle greet you.");
   set_listen("default","The wind blows lightly by. In the distance you hear a grunt.");
   set_exits(([
      "east":MONASTERY+"m12",
      "west":MONASTERY+"hall11",
      "north":MONASTERY+"m14",
      "south":MONASTERY+"m16",
      ]));
   set_invis_exits("west");
}

