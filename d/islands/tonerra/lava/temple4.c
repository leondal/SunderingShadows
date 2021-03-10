#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_property("no teleport",1);
  set_property("used sticks",1);
  set_short("Temple Proper");
  set_long(
@DESC
   %^BOLD%^%^RED%^The temple Proper%^RESET%^
This room is a broad chamber. It too simply another room
along a straight line of rooms. There is only one entrance
and only one exit it would appear. This room is quite clean.
The floor worn and the dust has not yet settled. You notice
that there are great divots in the floor wear some great claw
has dug into it.

DESC
  );
  set_listen("default","The lava flowing under your feet makes a strange buzzing sound.");
  set_smell("default","You smell the burning lava and hot rocks.");
  set_exits(([
    "out":LAVA+"temple3",
    "temple":LAVA+"temple5"

  ]));
  set_items(([
   "divots":"These were made by an extremely large creature. It appears that they were made in casual passage through this room."
   ]));
}

