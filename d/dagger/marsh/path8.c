#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(MARSH);
   set_travel(RUTTED_TRACK);
  set_property("light", 1);
  set_short("The Marsh Path");
  set("day long",
@GIL
%^ORANGE%^This is a path in the Deep, Dark Marsh.
Looking North and South the path leads onward.
You feel all alone as you walk under the giant cypress trees
and willows.
GIL
);
  set("night long",
@GIL
%^CYAN%^Darkness surrounds as you venture down this path in the
depths of the Deep Marsh.
Northwest and Southeast of you is a long dark path.
The sky is covered by the branches of giant cypress and willow trees.
GIL
);
set_smell("default", "%^GREEN%^You can smell the scent of the marsh, it stinks like rotting vegetation.");
set_listen("default", "%^BOLD%^%^BLUE%^You can hear loud frogs chirping and croaking all around.");
  set_items(([
"path" : "It looks wet and muddy and rarely traveled, no human footprints can be seen.",
"marsh" : "It looks deep and evil, monsters probably abound here in droves.",
"trees" : "Many Oaks and Willow trees dot the murky waters all around you.",
"footprints" : "They are many and definitely NOT human.",
"turtle" : "He must weigh 50 lbs at least, you wouldn't want him to bite you. They say they won't let go till lightning flashes.",
"bullfrog" : "Whoa he's big...must be a lot of insects around.",
]));

  set_exits(([
        "northwest":"/d/dagger/marsh/swamp/rooms/m_p009_n007",
        "northeast":"/d/guilds/pack/hall/firedock",
     "south" : "/d/dagger/marsh/path7",
]));
}
