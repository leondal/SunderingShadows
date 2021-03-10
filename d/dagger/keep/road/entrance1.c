#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(NEW_MOUNTS);
   set_travel(DIRT_ROAD);
set_property("light", 2);
  set_short("The drow cave entrance 1.");
  set("day long",
@GIL
%^BOLD%^This is small dirt road ending outside of a dark cave entrance.
The road heads back downhill to the Southeast.
Mt. Krakus towers above you, its craggy granite face is snowcapped
and bleak.
The cave looks dangerous and dark and a message is here, carved into the
side of the rock here.
GIL
);
  set("night long",
@GIL
%^CYAN%^This is small dirt road ending outside of a dark cave entrance.
The road heads back downhill to the Southeast.
The cave looks dark and dangerous and a message is here, carved into the
side of the rock here.
The wind howls whipping snow against your face in the cold darkness.
GIL
);
set_smell("default", "You can smell the clean scent of snow off Mt. Krakus.");
set_listen("default", "You can hear the waterfalls far to the East, as it falls off the side of Mt. Krakus.");
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
      "cave" : "/d/dagger/cave1/rooms/room1",
     "southeast" : "/d/dagger/keep/road/road12",
]));
}
void init()
{
::init();
add_action("read","read");

}
int read(string str)
{
if ((str=="message"))
{
write("%^BOLD%^If any seek the Drow, seek ye them within for there are no maps. %^YELLOW%^Yet Beware...for the Drow and the monsters of the Underdark do not offer mercy to fools. If thou not be a hero reknowned..Turn ye back now!");
return 1;
}
return 0;
}
