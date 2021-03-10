#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(NEW_MOUNTS);
   set_travel(DIRT_ROAD);
set_property("light", 2);
  set_short("The drow cave roads.");
  set("day long",
@GIL
%^BOLD%^This is a small dirt road.
It climbs up the flank of Mt. Krakus, legendary home of the Drow Elves.
To the Northwest up the steep road, you can see a cave entrance.
The road heads back downhill to the Southeast.
Mt. Krakus towers above you, its craggy granite face is snowcapped
and bleak.
The trees all disappear here on the rocky flank of the mountain.
GIL
);
  set("night long",
@GIL
%^CYAN%^This is a small dirt road.
It climbs up the flank of Mt. Krakus, legendary home of the Drow Elves.
To the Northwest the road steepens more.
The road heads back downhill to the Southeast.
The wind howls whipping snow against your face in the cold darkness.
GIL
);
set_smell("default", "You can smell the clean scent of snow off Mt. Krakus.");
set_listen("default", "You can hear the howl of the wind off Mt. Krakus.");
  set_items(([
"road" : "This is a small dirt road used for patrols up to Mt. Krakus.",
"trees" : "These trees are tall and majestic.",
"krakus" : "Mountain home of the Drow Elves, a bleak terrifing place.",
"mt. krakus" : "Mountain home of the drow Elves, a bleak terrifing place.",
]));

  set_exits(([
     "northwest" : "/d/dagger/keep/road/entrance1",
     "southeast" : "/d/dagger/keep/road/road11",
]));
}
