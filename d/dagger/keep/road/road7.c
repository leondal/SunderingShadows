#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(HEAVY_FOREST);
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
set_property("light", 2);
  set_short("The drow cave roads.");
  set("day long",
@GIL
%^BOLD%^This is a small dirt crossroads.
The road here splits suddenly heading North and Northwest.
The road heads back downhill through the thick evergreen forest Southward.
A small path that hardly attracts attention leads to the west.  A 
somewhat larger and more recent path leads to the east.
The ground continues to get steeper the closer you travel toward
Mt. Krakus to the North.
To the Northern directions the trees thin out as you climb upwards.
GIL
);
  set("night long",
@GIL
%^CYAN%^This is small dirt crossroads.
%^CYAN%^This is a small dirt crossroads.
The road heads back downhill through the thick evergreen forest Southward.
In the dark shadows to the west a trail can barely be made out.  Moonlight
reaches the path here through an opening in the trees to the east.
The ground continues to grow steeper the closer you travel toward
the flanks of Mt. Krakus to the North.
To the Northern directions the trees thin out as you climb upwards.
GIL
);
set_smell("default", "You can smell the clean scent of snow off Mt. Krakus.");
set_listen("default", "You can hear the sound of the wind in the trees.");
  set_items(([
"road" : "This is a small dirt road used for patrols into the mountains.",
"trees" : "These trees are tall and majestic.",
"meadow" : "This heather covered meadow lies between the evergreen forest and the tower Keep and village.",
"mt. krakus" : "Mt. Krakus, legendary home of the evil Drow Elves.",
"krakus" : "Mt. Krakus, legendary home of the evil Drow Elves.",
]));

  set_exits(([
     "north" : "/d/dagger/keep/road/road13",
     "east" : "/d/dagger/arctic/rooms/lake/road1",
     "northwest" : "/d/dagger/keep/road/road8",
     "south" : "/d/dagger/keep/road/road6",
     "west":"/d/dagger/derro/rooms/r7",
]));
}
