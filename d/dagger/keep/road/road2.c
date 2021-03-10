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
It plunges into a deep treeline of evergreens here.
The tower keep looms up into the sky to the Southeast.
The road travels into a thick evergreen forest here and heads North.
The road heads downhill across a meadow to the Southeast.
The ground continues to get steeper the closer you travel toward
the huge Dagger Realms Mountain Range rising into the skyline
to the North.
GIL
);
  set("night long",
@GIL
%^CYAN%^This is a small dirt road.
It plunges into a deep treeline of evergreens here.
To the Southeast you see the lights of a tower keep and a small trading
village near its walls.
The road travels into a thick evergreen forest here and heads North.
The road heads downhill across a meadow to the Southeast.
The ground continues to grow steeper the farther North you travel.
GIL
);
set_smell("default", "You can smell the clean scent of snow off the mountains.");
set_listen("default", "You can hear the sound of the wind in the trees.");
  set_items(([
"road" : "This is a small dirt road used for patrols into the mountains.",
"trees" : "These trees are tall and majestic.",
"lights" : "It might be a lantern or torch.",
"keep" : "It's tall and well fortified, from what you can see that is.",
"village" : "It looks like it sprang up to give the soldiers a way to spend their hard earned gold.",
"meadow" : "This heather covered meadow lies between the evergreen forest and the tower Keep and village.",
]));

  set_exits(([
     "north" : "/d/dagger/keep/road/road3",
     "southeast" : "/d/dagger/keep/road/road1",
]));
}
