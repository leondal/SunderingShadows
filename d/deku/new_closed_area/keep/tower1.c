#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Inside the Tower of Hawk");
  set_terrain(STONE_BUILDING);
  set_travel(PAVED_ROAD);
   set_long(
@KAYLA
%^YELLOW%^Inside the Tower of Hawk%^RESET%^
This large room is roughly 90' square with a large alcove set in 
the middle of each wall.  The floor is of highly polished marble
and the 20' high ceiling is of similar material.  The chamber
is dominated by a spiral, stone staircase leading to the level
above.
KAYLA
    );
     set_smell("default","Dust and ale permeate the walls of this tower.");
    set_exits(([
       "up" : "/d/deku/keep/tower2",
       "out" : "/d/deku/keep/keep2"
    ] ));
    set_items(([
    ] ));
}
