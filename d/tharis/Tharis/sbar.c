//sbar.c

#include <std.h>
#include "../tharis.h"

inherit ROOM;

void create(){
   ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
   set_property("light",1);
   set_property("indoors",1);

   set_short(
@JAVAMAKER
Safe house
JAVAMAKER
   );

   set_long(
@JAVAMAKER
    %^BOLD%^The safe house behind the bar%^RESET%^
This is the small safe house behind the bar. People often hide out
here when trying to lie low. The owner maintains the room
decently enough. There is a cot and a slit for food to be shoved
through. There is a small table around which the non to infrequent
meeting has been held concerning various issues.
JAVAMAKER
   );

   set_smell("default","There is a stale smell here. Wifts of dust tickle your nose.");
   set_listen("default","You hear the dull sound of conversation from the bar.");
   set_items(([
      "pictures":"These look to be of the palace gate. You notice that there appear to be doors drawn to the left and right of the gates.",
      "table":"This is a small dented table similar to the ones in the bar. It has some pictures carved in it.",
      "cot":"This is a dirty shirt thrown over some straw. ",
   ]));

   set_exits(([
      "out":ROOMS"mbar",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
   set_pre_exit_functions(({}),({}));
   set_post_exit_functions(({}),({}));
}




