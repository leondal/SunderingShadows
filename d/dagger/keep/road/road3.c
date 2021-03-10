#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(DIRT_ROAD);
set_property("light", 2);
  set_short("The drow cave roads.");
  set("day long",
@GIL
%^BOLD%^This is a small dirt road.
The road heads uphill Northward through a thick evergreen forest.
The road heads downhill toward a meadow to the South.
The ground continues to get steeper the closer you travel toward
the huge Dagger Realms Mountain Range rising into the skyline
to the North.
GIL
);
  set("night long",
@GIL
%^CYAN%^This is a small dirt road.
The road heads uphill Northward through a thick evergreen forest.
The road heads downhill toward a meadow to the South.
The ground continues to grow steeper the farther North you travel toward
the huge Dagger Realms Mountain Range.
GIL
);
set_smell("default", "You can smell the clean scent of snow off the mountains.");
set_listen("default", "You can hear the sound of the wind in the trees.");
  set_items(([
"road" : "This is a small dirt road used for patrols into the mountains.",
"trees" : "These trees are tall and majestic.",
"meadow" : "This heather covered meadow lies between the evergreen forest and the tower Keep and village.",
]));

  set_exits(([
     "north" : "/d/dagger/keep/road/road4",
     "south" : "/d/dagger/keep/road/road2",
]));
}
