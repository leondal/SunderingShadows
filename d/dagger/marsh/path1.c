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
Looking Northwest and Southeast the path leads deeper into the Marsh.
The deep thick marsh grows closer to the path.
Large willow trees draped with long grey moss stand thickly on both
sides of the path in the murky waters.
GIL
);
  set("night long",
@GIL
%^CYAN%^Darkness surrounds as you venture onto this path leading
into the depths of the Deep Marsh.
Northwest and Southeast of you is a long dark path leading
deeper into the marsh.
Loud croaks and chirps of frogs  all around you overwhelm your
senses and hearing.
GIL
);
set_smell("default", "%^GREEN%^You can smell the scent of the marsh, it stinks like rotting vegetation.");
   set_listen("default", "%^BOLD%^%^BLUE%^You can hear something thrashing its life out in the water nearby.");
  set_items(([
"path" : "It looks wet and muddy and rarely traveled, no human footprints can be seen.",
"marsh" : "It looks deep and evil, monsters probably abound here in droves.",
"trees" : "Many Oaks and Willow trees dot the murky waters all around you.",
]));

  set_exits(([
     "northwest" : "/d/dagger/marsh/path2",
     "southeast" : "/d/dagger/marsh/marsh1",
]));
}
