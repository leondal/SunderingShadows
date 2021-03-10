#include <std.h>
inherit ROOM;

void create()
{
  ::create();
  set_property("light", 2);
  set_short("The South Branch.");
  set("day long",
@GIL
%^GREEN%^You are out on the South limb of the huge oak tree.
The leaves close around you and green is all you can see.
You can only go North.
GIL
);
  set("night long",
@GIL
%^CYAN%^You are out on the North limb of the huge oak tree.
The dark closes around you as the leaves block out all light.
You can only go South.
GIL
);
set_smell("default", "%^BOLD%^%^GREEN%^You can smell the fresh smell of oak leaves.");
set_listen("default", "You can hear the wind in the oak leaves.");
  set_items(([
"leaves" : "The leaves are dark green and full of life.",
"tree" : "This huge oak grows beside the road.",
"limb" : "This is a big limb growing South over the forest.",
]));

set_exits(([
     "north" : "/d/dagger/westroad/tree1",
]));
}
