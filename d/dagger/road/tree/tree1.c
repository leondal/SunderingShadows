#include <std.h>
inherit ROOM;

void create()
{
  ::create();
  set_property("light", 2);
  set_short("The Tree.");
  set("day long",
@GIL
%^GREEN%^You are halfway up a huge oak tree that grows beside
the Dagger Sea coast road. Growling noises can be heard above you.
The leaves close around you and green is all you can see.
You can go Up, Down, East, West, North or South.
GIL
);
  set("night long",
@GIL
%^CYAN%^You are halfway up a huge oak tree that grows beside
the Dagger Sea coast road. You hear breathing close by.
The dark closes around you as the leaves block out all light.
You can go Up, Down, East, West, North or South
GIL
);
set_smell("default", "%^BOLD%^%^GREEN%^You can smell the fresh smell of oak leaves.");
set_listen("default", "You can hear the wind in the oak leaves.");
  set_items(([
"leaves" : "The leaves are dark green and full of life.",
"tree" : "This huge oak grows beside the road."
]));

  set_exits(([
     "up" : "/d/dagger/westroad/tree2",
     "down" : "/d/dagger/westroad/road8",
     "east" : "/d/dagger/westroad/branch1",
     "west" : "/d/dagger/westroad/branch2",
     "north" : "/d/dagger/westroad/branch3",
     "south" : "/d/dagger/westroad/branch4",
     ]));
}
