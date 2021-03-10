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
%^ORANGE%^This is the path leading into the Deep, Dark Marsh.
Looking Northwest and Southeast the path leads onward.
The marsh grows even thicker and darker, the trees close in on the
path cutting out the sunlight.
The path is disturbed here by clawed footprints as tho a fight
had taken place.
You wonder who or what was killed because theres blood everywhere.
GIL
);
  set("night long",
@GIL
%^CYAN%^Darkness surrounds as you venture onto this path leading
into the depths of the Deep Marsh.
Northwest and Southeast of you is a long dark path.
The path is disturbed here by clawed footprints as tho a fight
had taken place.
You wonder who or what was killed, because theres blood everywhere.
GIL
);
set_smell("default", "%^GREEN%^You can smell the scent of the marsh, it stinks like rotting vegetation.");
   set_listen("default", "%^BOLD%^%^BLUE%^You can hear something thrashing its life out in the water nearby.");
  set_items(([
"path" : "It looks wet and muddy and rarely traveled, no human footprints can be seen.",
"marsh" : "It looks deep and evil, monsters probably abound here in droves.",
"trees" : "Many Oaks and Willow trees dot the murky waters all around you.",
"footprints" : "They are many and definitely NOT human.",
"blood" : "Gods...It's everywhere...splattered and gushed all over....ugh! Whatever died here..died violently.",
]));

  set_exits(([
     "northwest" : "/d/dagger/marsh/path3",
     "southeast" : "/d/dagger/marsh/path1",
]));
}
