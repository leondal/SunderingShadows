#include <std.h>
inherit ROOM;

void create()
{
  ::create();
  set_property("light", 2);
  set_short("The West Branch.");
  set("day long",
@GIL
%^GREEN%^You are out on the West limb of the huge oak tree.
A tangle of sticks making up a large nest is here.
The leaves close around you and green is all you can see.
You can only go East.
GIL
);
  set("night long",
@GIL
%^CYAN%^You are out on the West limb of the huge oak tree.
A tangle of sticks making up a large nest is here.
The dark closes around you as the leaves block out all light.
You can only go East.
GIL
);
set_smell("default", "%^BOLD%^%^GREEN%^You can smell the fresh smell of oak leaves.");
set_listen("default", "You can hear the wind in the oak leaves.");
  set_items(([
"leaves" : "The leaves are dark green and full of life.",
"tree" : "This huge oak grows beside the road.",
"nest" : "It's a large Nest, you wonder what lives here?",
"limb" : "This is a big limb growing West over the forest.",
]));

set_exits(([
     "east" : "/d/dagger/westroad/tree1",
]));
}
