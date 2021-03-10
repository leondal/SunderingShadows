#include <std.h>
#include "../piratedefs.h"

inherit CROOM;

void create(){ 
   set_monsters(({MON"pirateguard.c"}),({4}));
   ::create();
    set_repop(50);
   set_property("light",2);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
   set_short( "West docks" );
   set_long(
            "%^BOLD%^West Docks%^RESET%^\n"+
             "You have walked onto the west docks and "+
             "now have a full view of the ship. "+
               "She is gorgeous.  Her figurine is of a beautiful elven woman. "+
            "On closer inspection you see that she has a few dings, "+
          "but you still marvel at the craftsmanship.  A gangplank leads onboard "+
        "the ship.\n"
   );

   set_smell("default","You smell fresh ocean air.");
set_listen("default","You hear water sloshing up against the docks.");

   set_items(([
   "ocean":"The ocean spreads out before you to the horizon.",
     "ship":"She's a beaut all right.",
    "deck":"You can see the crew trying to repair some of the damage."
    ]));

   set_exits(([
   "east":CAVES"cove14",
   "gangplank":CAVES"ship2r2"
]));

set_pre_exit_functions(({"gangplank",}),({"stopem",}));

}

void reset(){
   ::reset();
/* don't need these with using CROOM and setting the mobs above.
In fact, it defeats the purpose of the control on respawning CROOM handles until after those are killed.

if(!present("pirate")){
        new(MON+"pirateguard")->move(TO);
}
   if(!present("pirate 2")){
        new(MON+"pirateguard")->move(TO);
}
   if(!present("pirate 3")){
        new(MON+"pirateguard")->move(TO);
}
   if(!present("pirate 4")){
        new(MON+"pirateguard")->move(TO);
   }
*/
}

int stopem(){
  if(wizardp(TP)) return 1;
    if(present("pirate")){
        if(!TP->query_invis()){
              write("%^MAGENTA%^Pirate says:%^RESET%^Get outta my face");
            return 0;
        }else{
            write("You sneak over the gangplank");
                return 1;}
}else{
        write("You walk over the gangplank");
        return 1;}

}
