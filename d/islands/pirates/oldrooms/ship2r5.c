#include <std.h>
#include "../piratedefs.h"

inherit CROOM;

void create(){
set_monsters(({MON"piratethiefw.c",MON"piratefighter.c"}),({2,2}));
::create();
    set_repop(50);

set_property("light",2);
    set_terrain(BARREN);
    set_travel(DECAYED_FLOOR);
set_short("%^BOLD%^Forecastle%^RESET%^");

set_long("%^BOLD%^Forecastle%^RESET%^\n"+
         "You have walked to the bow of the ship. "+
         "You can see clear across the ship to the poopdeck "+
         "from here. It's quiet up here, but it leaves you feeling "+
         "exposed."
"\n"
        );

set_smell("default","You smell fresh ocean air minced with the smell of hemp and wood.");
set_listen("default","You can hear the sound of the ship's crew working.");
set_items(([
   "crates":"These are full of spices",
   "rope":"The ropes are coiled neatly, awaiting use.",
   "sails":"The sails look worn.",
   "helm":"The wheel is worn but very well crafted.",
         ]));

set_exits(([
           "maindeck":CAVES"ship2r2",
          ]));

}

