#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(BARREN);
   set_travel(DIRT_ROAD);
  set_property("light", 2);
  set_short("The Wooden Bridge over the Krakus River.");
  set("day long",
@GIL
%^BOLD%^This is the wooden bridge over the Krakus River.
On the patrol road that leads from Lookout Keep to Mt. Krakus.
To the North and South the road leads back into the evergreen forest.
Northeast and Southwest of you is the river leading into a forest of
evergreen trees.
GIL
);
  set("night long",
@GIL
%^CYAN%^This is the wooden bridge over the Krakus River.
On the patrol road leading from Lookout Keep to Mt. Krakus.
North and South of you is a dark road leading back into the trees.
Northeast and Southwest of you is the river leading into a forest of
evergreen trees.
GIL
);
set_smell("default", "You smell the scent of clean water.");
set_listen("default", "You can hear the river splashing against the rocks below.");
  set_items(([
"road" : "This is a small dirt patrol road leading through the forest.",
"trees" : "They are tall and majestic and grow close together.",
"bridge" : "It's made of large evergreen logs and solidly made.",
"river" : "The river current appears strong and the water looks cool and clean."
]));

  set_exits(([
     "north" : "/d/dagger/keep/road/road6",
     "south" : "/d/dagger/keep/road/road5",
]));
}
