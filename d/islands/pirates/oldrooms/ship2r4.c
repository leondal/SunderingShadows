#include <std.h>
#include "../piratedefs.h"

inherit CROOM;

void create(){
    set_monsters(({MON"piratefighter", MON"firstmate"}),({2, 1}));
    ::create();
    set_repop(50);
    set_property("light",1);
    set_terrain(BARREN);
    set_travel(DECAYED_FLOOR);
    set_short("Poop deck");

    set_long("%^BOLD%^Poop deck%^RESET%^\n"+
         "You have walked to the stern of the ship. "+
          "This is where the helm of the ship is to be found. "+
         "You have a good view of the rest of the ship from "+
         "here.\n"
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
           "quarterdeck":CAVES"ship2r3",
          ]));
}

void reset(){
 ::reset();
/*  changing to let the CROOM handle him too  *Styx*  11/25/02
 if(!present("first mate") && !random(2)){
   find_object_or_load(MON+"firstmate")->move(TO);
 }
*/
}

