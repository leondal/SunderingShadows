#include <std.h>
#include "../piratedefs.h"

inherit CROOM;

void create(){ 
set_monsters(({MON"pirateguard.c"}),({4}));
   ::create();
    set_repop(50);
   set_property("light",2);
   set_short(   "East docks"   );
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);

   set_long(
            "%^BOLD%^East Docks%^RESET%^\n"+
            "You have walked onto the east docks and "+
             "now have a full view of the ship. "+
            "It's pretty beat up and looks like she was just "+
            "captured.  There is a gangplank that will "+
            "allow you access to the ship.\n"
   );

   set_smell("default","You smell fresh ocean air.");
set_listen("default","You can hear water sloshing against the docks.");

   set_items(([
   "ocean":"The ocean spreads out before you to the horizon.",
   "ship":"The ship is pretty beat up.",
   "deck":"You can see her crew trying to repair some of the damage.",
    ]));

   set_exits(([
   "west":CAVES"cove14",
   "gangplank":CAVES"ship1r2"
]));

set_pre_exit_functions(({"gangplank",}),({"stopem",}));

}

void reset(){
   ::reset();
/* changed to using CROOM since they wander
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
            write("You sneak over the gangplank.");
                return 1;}
}else{
        write("You walk over the gangplank");
        return 1;}

}

