//cave9.c
#include "../kildare.h"

inherit CAVE;

void create()
{
   ::create();
   set_short("Large Cavern");
   set_long(
@CIRCE
%^BOLD%^%^CYAN%^A Large Cavern
%^RESET%^%^CYAN%^Just inside Echoes Mountains, a small entrance opens 
up into a large cavern.  The stairway to the south leads deeper into the 
mountain caverns, while the northern wall houses an opening out of the 
caves.  Rough carvings on the wall and footprints in the light dirt 
covering the floor suggest that this cave is more in use than the 
passageway itself, though it seems to be empty at the moment.  
Hooks and pegs have been hammered into the walls at regular intervals, 
but nothing hangs from them now.
CIRCE
    );

   set_items(([
      "steps" : "The steep slope of the cavern floor has been made "+
      "easier by roughly hewn steps leading downwards to the south.",
      "cavern" : "The dark walls of this cavern seem to be "+
      "hewn rather than naturally carved as the rest of Echoes Mountains.",
      ({"floor","ceiling","stone"}) : "The ceiling seems to be very roughly hewn "+
      "while the dark stone floor has been worn smooth.",
      ({"wall","walls"}) : "The walls of this large cave have been riddled with "+
      "various hooks and pegs spread at regular intervals.",
      ({"peg","pegs","hook","hooks"}) : "Wooden pegs and iron hooks have been "+
      "driven into the walls, but hang empty now.  Upon closer inspection, you "+
      "see what seems to be a dried red substance below some of them.",
      ({"substance","dried substance","red substance","dried red substance"}) : "It "+
      "seems to be dried blood of some kind.  None of it seems very fresh.",
      ({"carvings","rough carvings"}) : "The carvings on the wall are no more than "+
      "three feet high and seem to be the work of either a very poor artist or a "+
      "child.  They are all scraped into the wall and depict various outdoor "+
      "scenes, such as clouds, trees, and animals.",
      ({"footprints","prints"}) : "The footprints seem to be human-sized, with some "+
      "much smaller sets that could belong to children.  A thin layer of dirt is now "+
      "beginning to cover them, suggesting that this cave has not been visited "+
      "recently."
   ]));

   set_smell("default","You smell the fresh scent of the outdoors.");

    set_exits(([
      "down" : ROOMS"cave8",
      "out" : TROOMS"path1"
        ]));

}
