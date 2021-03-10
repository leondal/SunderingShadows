//changed to use search to reveal the hidden exit - Saide
#include <std.h>
#include "/d/deku/inherits/deku.h"

inherit HH_ROOMS+"hall1i";

void create() {
    ::create();
    set_long(
@KAYLA
The front door opens onto this musty, dirty entrance hall.  To your
left a corridor leads into the west wing of the house.  On either
side of the corridor opening the walls are bare.  Ahead of you,
another corridor leads towards the rear of the house.  To your
right a staircase climbs to the next story.
KAYLA
    );
   set_search("default","You look around the area carefully and notice a slightly concealed exit beneath the stairwell that leads into the east wing of the house.");
   set_listen("default","There is a howl in the distance, or maybe it was the wind.");
   set_exits(([
    "up" : HH_ROOMS+"stair",
    "south" : "/d/deku/town/road12",
    "west" : HH_ROOMS+"hall1i",
    "east" : HH_ROOMS+"hall3",
    "north" : HH_ROOMS+"hall2"
    ] ));
    set_invis_exits(({"east"}));
    //set_pre_exit_functions(({"north"}),({"go_north"}));
    set_items(([
       "stair" : "Although old, the stairs looks as if they are safe enough."
    ] ));
    hauntings();
}

/*int go_north() {
  write("As you move northward, you notice there was a somewhat concealed "
  "opening leading to the east wing of the Haunted House from "
  "the room you just left.\n");
  return 1;
}*/
