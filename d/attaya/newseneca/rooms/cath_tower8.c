//cath_tower8 - bell tower for new Seneca
//~Circe~ 1/14/08
#include <std.h>
#include "../seneca.h"

inherit STORAGE"cath_tower";

void create(){
   ::create();
   set_long(::query_long()+"\nThis portion of the stairway is "+
      "just below the huge %^ORANGE%^brass bells %^RESET%^"+
      "that hang from a %^ORANGE%^beam %^RESET%^above.  This "+
      "high up, the rooftops of Seneca appear to be colored "+
      "blotches below.\n");
   set_exits(([
      "down" : ROOMS"cath_tower7",
      "up" : ROOMS"cath_tower9"
   ]));
   add_item("bells","%^ORANGE%^The two %^BOLD%^brass bells "+
      "%^RESET%^%^ORANGE%^hang from a beam above.  From here, "+
      "you can see the great open circle of each bell's base "+
      "and the clapper that causes each bell to ring.%^RESET%^");
   add_item("brass bells","%^ORANGE%^The two %^BOLD%^brass bells "+
      "%^RESET%^%^ORANGE%^hang from a beam above.  From here, "+
      "you can see the great open circle of each bell's base "+
      "and the clapper that causes each bell to ring.%^RESET%^");
   add_item("bell","%^ORANGE%^The two %^BOLD%^brass bells "+
      "%^RESET%^%^ORANGE%^hang from a beam above.  From here, "+
      "you can see the great open circle of each bell's base "+
      "and the clapper that causes each bell to ring.%^RESET%^");
   add_item("beam","%^ORANGE%^The thick wooden beam runs into "+
      "the very sandstone of the walls, making the structure "+
      "stable.  The bells are lashed to the beam with a "+
      "thickly braided rope.  Another rope extends below the "+
      "bells and may be pulled to ring them, but it is out of "+
      "reach here.%^RESET%^");
}