#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){
::create();

set_property("light",2);
set_short("Main Deck");
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);

set_long("%^BOLD%^Main Deck%^RESET%^\n"+
"The masts have been smashed down and the deck is charred and weakened. "
"This ship looks like it has seen better days.  The cargo seems to have been "
"looted already.  Traveling anywhere else on this dying ship would be too "
"dangerous right now.  A gangplank leads back to the dock.\n"
        );
set_smell("default","You smell fresh ocean air minced with the smell of charred wood.");
set_listen("default","You hear the boards of the ship creak in an unsettling way.");

set_items(([
   "crates":"These are full of spices.",
   "rope":"The ropes are coiled neatly awaiting use.",
   "sails":"The sails look worn.",
         ]));

set_exits(([
           "dock":CAVES"ship1r1",
          ]));

}
