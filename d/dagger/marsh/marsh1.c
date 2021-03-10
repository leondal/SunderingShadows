#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(MARSH);
   set_travel(RUTTED_TRACK);
  set_property("light", 2);
  set_short("The Marsh Pathway.");
  set("day long",
@GIL
%^ORANGE%^This is the pathway leading into the Deep, Dark Marsh.
Looking Northwest the pathway leads deeper into the Marsh.
Back to the Southeast is the Dagger Sea Coast Road.
The deep thick marsh closes in around you and you feel quite alone.
Frogs chirp and grunt all around you in the murky waters.
GIL
);
  set("night long",
@GIL
%^CYAN%^Darkness surrounds as you venture onto this pathway leading
into the depths of the Deep, Dark Marsh.
Northwest of you is a long dark pathway leading deeper into the marsh.
Back to the Southeast is the Dagger Sea Coast Road.
The marsh deepens and grows thicker here and occasionally you hear what
you know isn't an animal, deep inside the marsh.
Suddenly something whispers in your ear...'GET OUT!!!'
GIL
);
set_smell("default", "%^GREEN%^You can smell the scent of the marsh, it stinks like rotting vegetation.");
   set_listen("default", "%^BOLD%^%^BLUE%^You can hear something thrashing its life out in the water nearby.");
  set_items(([
"pathway" : "It looks wet and muddy and rarely traveled, no human footprints can be seen.",
"marsh" : "It looks deep and evil, monsters probably abound here in droves."
]));

  set_exits(([
     "northwest" : "/d/dagger/marsh/path1",
"southeast" : "/d/dagger/road/road41",
]));
}
