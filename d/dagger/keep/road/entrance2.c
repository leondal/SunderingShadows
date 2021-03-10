#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(NEW_MOUNTS);
   set_travel(DIRT_ROAD);
set_property("light", 2);
set_short("Entrance to the cave of the ogre hordes");
  set("day long",
@GIL
%^BOLD%^This is small dirt road ending outside of a dark cave entrance.
The road heads back downhill to the South.
To the far East you can see a waterfall.
Mt. Krakus towers above you, its craggy granite face is snowcapped
and bleak.
GIL
);
  set("night long",
@GIL
%^CYAN%^This is small dirt road ending outside of a dark cave entrance.
The road heads back downhill to the Southeast.
To the far East you can hear a waterfall falls.
The wind howls whipping snow against your face in the cold darkness.
GIL
);
set_smell("default", "You can smell the clean scent of snow off Mt. Krakus.");
set_listen("default", "You can hear the loud waterfall to the East, pounding into your ears as it falls off the side of Mt. Krakus and into the chasm below it.");
  set_items(([
"road" : "This is a small dirt road used for patrols up to Mt. Krakus.",
"trees" : "These trees are tall and majestic.",
"krakus" : "Mountain home of the Drow Elves, a bleak terrifing place.",
"mt. krakus" : "Mountain home of the drow Elves, a bleak terrifing place.",
"cave" : "This is one of the dangerous entrances into the Underdark, land of the Drow and other monsters.",
"message" : "Try reading it",
"waterfall" : "Over 500 feet high, it pours with pounding force into the deep, dark chasm below it!",
]));

  set_exits(([
     "cave" : "/d/dagger/ogres/rooms/0_2",
     "south" : "/d/dagger/keep/road/road17",
]));
}
