#include <std.h>
#include "../piratedefs.h"
int opengrate;
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",2);
   set_terrain(SCRUB_LANDS);
   set_travel(FOOT_PATH);
   set_short( "Secret Clearing" );

   set_long(
            "%^BOLD%^Secret Clearing%^RESET%^\n"+
"You have passed through the bushes "+
"and have arrived at an overgrown cobbled street. "+
"The only thing of interest is a heavy iron grate "+
"which sits in the middle of this cobbled clearing. "+
"The only obvious exit is south through the bushes."
"\n"
   );

   set_smell("default","You smell fresh ocean air.");
set_listen("default","You can hear waves crashing on shore.");

   set_items(([
    "ocean":"The ocean spreads out before you to the horizen.",
    "village":"You can now have a clear view of the village buildings." +
              " They seem to have been built out of pieces of old ships.",
    "streets":"The streets are more like paths but they get the job done.",
     "grate":"This is an old rusted grate, you'll have to lift it to get down there."
    ]));

   set_exits(([
   "south":CAVES"cove9",
   "down":CAVES"thief2"
]));
set_pre_exit_functions(({"down"}),({"grateit"}));
set_invis_exits(({"down"}));

}
void init(){
 ::init();
 add_action("lift","lift");
}


int lift(string str){
 if (!str) return notify_fail("Lift what?\n");
if (str !="grate") return notify_fail("What are you trying to lift?\n");
if(opengrate==1) return notify_fail("The grate has been moved already\n");
if((roll_dice(1,20))>(TP->query_stats("strength"))) return notify_fail("You find you are too weak to lift the grate.\n");

else{
  tell_object(TP,"You lift a heavy grate off the hole.");
tell_room(environment(TP),""+TPQCN+" lifts a heavy looking grate",TP);
opengrate=1;
return 1;
}
}

int grateit(){

if(wizardp(TP)) return 1;
        if(opengrate==0){
             write("A rusted iron grate blocks your path.");
            return 0;
        }else{
             write("You descend underground.");
            return 1;}
}


void reset(){
   ::reset();
    opengrate=0; 
}
