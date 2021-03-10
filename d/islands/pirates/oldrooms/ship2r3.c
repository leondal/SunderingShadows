#include <std.h>
#include "../piratedefs.h"

inherit CROOM;

void create(){
set_monsters(({MON"piratecrew.c"}),({2}));
::create();
    set_repop(60);

set_property("light",2);
    set_terrain(BARREN);
    set_travel(DECAYED_FLOOR);
set_short("Quarter Deck");

set_long("%^BOLD%^Quarter deck%^RESET%^\n"+
         "The sails lay here neatly folded. "+
         "You have a nice view of the main deck from here. "+
       "There are a few barrels scattered about.\n"
        );

set_smell("default","You smell fresh ocean air minced with the smell of hemp and wood.");
set_listen("default","You can hear the sound of the ship's crew working.");
set_items(([
   "sails":"The sails look worn.", 
   "barrels":"These barrels are filled with water.",
         ]));

set_exits(([
           "maindeck":CAVES"ship2r2",
           "poopdeck":CAVES"ship2r4",
          ]));

}
