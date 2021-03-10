#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(MARSH);
   set_travel(RUTTED_TRACK);
  set_property("light", 2);
  set_short("The Marsh Path");
  set("day long",
@GIL
%^ORANGE%^This is the path in the Deep, Dark Marsh.
Looking Northwest and Southeast the path leads onward.
The marsh grows even thicker and darker, the trees close in on the
path cutting out the sunlight.
A trail of clawed footprints leads Northwest and Southeast.
You can see drops of blood here.
GIL
);
  set("night long",
@GIL
%^CYAN%^Darkness surrounds as you venture down this path in the
depths of the Deep Marsh.
Northwest and Southeast of you is a long dark path.
A trail of clawed footprints leads Northwest and Southeast.
You can see drops of blood here.
GIL
);
set_smell("default", "%^GREEN%^You can smell the scent of the marsh, it stinks like rotting vegetation.");
set_listen("default", "%^BOLD%^%^BLUE%^You can hear loud frogs chirping and croaking all around.");
  set_items(([
"path" : "It looks wet and muddy and rarely traveled, no human footprints can be seen.",
"marsh" : "It looks deep and evil, monsters probably abound here in droves.",
"trees" : "Many Oaks and Willow trees dot the murky waters all around you.",
"footprints" : "They are many and definitely NOT human.",
"blood" : "There is drops it leading both ways down the path.",
]));

  set_exits(([
     "northwest" : "/d/dagger/marsh/path5",
     "southeast" : "/d/dagger/marsh/path3",
]));
}
