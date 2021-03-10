#include <std.h>
#include "../piratedefs.h"

inherit CROOM;

void create(){
set_monsters(({MON"piratefighter.c",MON"piratecrew.c"}),({2,2}));
::create();
    set_repop(50);
set_property("light",1);
    set_terrain(BARREN);
    set_travel(DECAYED_FLOOR);
set_short("%^BOLD%^Main Deck%^RESET%^");
set_long("%^BOLD%^Main Deck%^RESET%^\n"+
         "The masts cast long shadows across the deck. "+
         "Several coils of rope and crates of cargo clutter the deck.  "
         "The sails have been lowered and a gangplank leads off the "
         "ship back to the dock.\n"
        );
set_smell("default","You smell fresh ocean air minced with the smell of hemp and wood.");
set_listen("default","You can hear the sound of the ship's crew working.");

set_items(([
            "crates":"These are full of spices.",
            "rope":"The ropes are coiled neatly, awaiting use.",
            "sails":"The sails look worn."
         ]));

set_exits(([
           "quarterdeck":CAVES"ship2r3",
           "dock":CAVES"ship2r1",
           "forecastle":CAVES"ship2r5",
           "down":CAVES"ship2r11",
           "north":CAVES"ship2r6",
           "south":CAVES"ship2r7"
          ]));
}
