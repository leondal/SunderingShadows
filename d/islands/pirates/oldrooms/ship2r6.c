#include <std.h>
#include "../piratedefs.h"

inherit CROOM;

void create(){
  set_monsters(({MON+"piratefighter",MON+"piratecrew"}),({3,2}));
::create();
    set_repop(50);

set_property("indoors",1);
set_property("light",2);
    set_terrain(WOOD_BUILDING);
    set_travel(DECAYED_FLOOR);

set_short("Bunk Room");

set_long("%^BOLD%^Bunk Room%^RESET%^\n"+
         "This room is filled with the sound of snoring. "+
          "Clothes and various other things are scattered about. "+
          "There are several hammocks here.  It is very cramped in here "+
         "as is the rest of the ship.\n"
        );

set_smell("default","You smell stale and thick air.");
set_listen("default","You can hear the sound of snoring.");
set_items(([
   "hammocks":"These look very uncomfortable.",
   "clothes":"This place is cramped enough with out this junk cluttering it up.",
         ]));

set_exits(([
           "south":CAVES"ship2r2",
          ]));

}

