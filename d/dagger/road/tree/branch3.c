#include <std.h>
inherit ROOM;

void create()
{
  ::create();
  set_property("light", 2);
  set_short("The North Branch.");
  set("day long",
@GIL
%^GREEN%^You are out on the North limb of the huge oak tree.
Hmm this is odd, theres a strange knot on the limb.
The leaves close around you and green is all you can see.
You can only go South.
GIL
);
  set("night long",
@GIL
%^CYAN%^You are out on the North limb of the huge oak tree.
Hmm..this is odd, theres a strange knot on the limb.
The dark closes around you as the leaves block out all light.
You can go South.
GIL
);
set_smell("default", "%^BOLD%^%^GREEN%^You can smell the fresh smell of oak leaves.");
set_listen("default", "You can hear the wind in the oak leaves.");
  set_items(([
"leaves" : "The leaves are dark green and full of life.",
"tree" : "This huge oak grows beside the road.",
"knot" : "It's a large wierd looking knot, growing on the branch. There appears to be a symbol carved in it.",
"limb" : "This is a big limb growing North over the forest.",
"symbol" : "It looks like this ~*~ ",
"~*~" : "For some odd reason...you want to touch it.",
]));

set_exits(([
     "south" : "/d/dagger/westroad/tree1",
]));
}
void init() {
  ::init();

  add_action("touch_symbol","touch");
}

int touch_symbol(string str) {
  if(!str) {
    write("Touch what?");
    return 1;
  }
  if((str == "symbol") || (str=="~*~")){
  write("%^BOLD%^You feel dizzy for a moment, then notice your surroundings have changed.");
  say("%^BOLD%^"+this_player()->query_cap_name()+" touches a strange knot on the branch and suddenly disappears.");
  this_player()->move_player("/d/dagger/westroad/road8");
  return 1;
  }
}
