//m4.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Old Library");
   set_short("Old Library");
   set_property("no teleport",1);
   set_property("indoors",1);
   set_property("light",2);
   set_long(
@OLI
   %^ORANGE%^An Old Library%^RESET%^
%^RESET%^This is an old library. Many eons of %^BOLD%^knowledge%^RESET%^ must be stored here.
Secrets of time, space, history and the future reside here. Large
old %^ORANGE%^shelves%^RESET%^ rise high into the ceiling here. %^MAGENTA%^Books%^RESET%^ are stacked neatly
in some places, thrown in in others. %^BOLD%^Dust%^RESET%^ covers most of the stacks,
but some of them look as if they are frequently used. The monks must study here. An old %^BOLD%^metal staircase%^RESET%^ twists upward here. Looking up, you see
another level above you.
OLI
   );

   set_items(([
      "books":"These books look used and old. Great knowledge is stored here.",
      "shelves":"You notice the shelves here are full of dusty, must covered books.",
      "staircase":"This is and old ornate staircase.  It twists tightly upward, so that only one can pass at a time",
      ]));
   set_exits(([

      "staircase":MONASTERY+"m21",
      "south":MONASTERY+"m18",
      ]));
   set_smell("default","An odor of must and dust is dominant here.");
   set_listen("default","You seem to hear long dead whispers.");
}

