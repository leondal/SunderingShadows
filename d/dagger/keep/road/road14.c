#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
set_property("light", 2);
  set_short("The drow cave roads.");
  set("day long",
@GIL
%^BOLD%^This is a small dirt road.
It plunges closer through the thinning evergreen trees, climbing up the
flanks of Mt. Krakus, legendary home of the Drow Elves.
The road steepens to the Northwest.
The road heads back downhill to the South.
Mt. Krakus towers into the sky to the North, its craggy granite face
is snowcapped and bleak.
The sun is bright in these higher altitudes, you also begin to find
breathing a bit harder.
GIL
);
  set("night long",
@GIL
%^CYAN%^This is a small dirt road.
It plunges closer through the dark evergreens, climbing up the flanks of
Mt. Krakus, legendary home of the Drow Elves.
The road steepens to the Northwest.
The road heads back downhill to the South.
All around you the wind whips light snow in the cold darkness.
GIL
);
set_smell("default", "You can smell the clean scent of snow off Mt. Krakus.");
set_listen("default", "You can hear the sound of the wind in the trees.");
  set_items(([
"road" : "This is a small dirt road used for patrols up to Mt. Krakus.",
"trees" : "These trees are tall and majestic.",
"krakus" : "Mountain home of the Drow Elves, a bleak terrifing place.",
"mt. krakus" : "Mountain home of the drow Elves, a bleak terrifing place.",
]));

  set_exits(([
     "northwest" : "/d/dagger/keep/road/road15",
     "south" : "/d/dagger/keep/road/road13",
]));
}
