#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_terrain(SCRUB_LANDS);
   set_travel(DIRT_ROAD);
   set_short( "Overgrown Path"  );
   set_long(
            "%^BOLD%^Overgrown Path%^RESET%^\n"+
            "You have gone north of the town square. "+
            "There is not a soul to be seen save yourself. "+
            "The road further is blocked by bushes and trees."
"\n"
   );

   set_smell("default","You smell fresh ocean air.");
set_listen("default","You can hear waves crashing on shore.");

   set_items(([
     "ocean":"The ocean spreads out before you to the horizon.",
    "village":"You can now have a clear view of the village buildings. 
They seem to have been built out of pieces of old ships.",
    "streets":"The streets are more like paths but they get the job
done.",
    ]));

   set_exits(([
   "south":CAVES"cove8",
   "bushes":CAVES"thief1"
]));
set_pre_exit_functions(({"bushes",}),({"stopem",}));
set_invis_exits(({"bushes"}));
}

  int stopem(){
if(wizardp(TP)) return 1;
        if(!TP->is_class("thief")&&!TP->is_class("assassin")){
             write("The bushes are rather thick and sharp, passage will be too difficult.");
            return 0;}
        else{
             write("You sneak through the bushes quietly.");
            return 1;}
}
