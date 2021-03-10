//cove3.c

#include <std.h>
#include "../piratedefs.h"

inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);

   set_short(
@JAVAMAKER
Bridge
JAVAMAKER
   );

   set_long(
@JAVAMAKER
%^BOLD%^%^WHITE%^Bridge%^RESET%^
You have reached the bridge proper.  It spans a division in the cliffs
made by an inlet.  You can see the village quite well now.  You can
head north back up the trail to the caves or you can head south
down to the village and docks.
JAVAMAKER
   );

   set_smell("default","You smell fresh ocean air.");
set_listen("default","You can hear waves crashing on shore.");
   set_items(([
       "ocean":"The ocean spreads out before you to the horizon.",
       "village":"You now have a clear view of the village buildings.  They seem to have been built out of pieces of old ships.",
      "Bridge":"This stone bridge looks sturdy enough.",
      "streets":"The streets are more like paths but they get the job done.",
   ]));

   set_exits(([
      "north":CAVES"cove2",
      "south":CAVES"cove4",
   ]));

   set_invis_exits(({}));
   set_trap_functions(({}),({}),({}));
set_pre_exit_functions(({"south",}),({"stopem",}));
}


void reset(){
   ::reset();
   if(!present("pirate")){
        new(MON+"pirateguard.c")->move(TO);
        new(MON+"pirateguard.c")->move(TO);
   }
}

void init(){
   ::init();

}

int stopem(){
  if(wizardp(TP) || TP->query_true_invis()) return 1;
    if(present("pirate")){
        if(!TP->is_class("thief")){
            write("%^MAGENTA%^Pirate says:  %^BOLD%^%^WHITE%^Go back fore I kick yer scurvy ridden Behind ya Land lover!%^RESET%^");
            return 0;}
        else{
            write("%^MAGENTA%^Pirate says:  %^BOLD%^%^WHITE%^Go on with ya 'fore I change my mind ya scurvy ridden seadog!");
 write("%^BOLD%^You walk across the bridge%^RESET%^");
            return 1;}
    }else{
        write("%^BOLD%^You walk across the bridge.%^RESET%^");
        return 1;}
}
