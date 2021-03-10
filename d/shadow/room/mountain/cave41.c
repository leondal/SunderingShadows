//cave41.c
#include <std.h>
#include "echoes.h"
#define RANDSTUFF "/d/common/daemon/randstuff_d"

inherit OGRES;
int searched;
int attacked;

void create(){
    ::create();
    set_long(
      "%^YELLOW%^Inside Echoes Mountains%^RESET%^\n"+
      "You are in an alcove situated on a ledge well above the floor of the cavern.  "+
      "From here, it is easy to see where the curved archways meet the ceiling.  No "+
      "columns have been carved here, and it looks as though this might have been a "+
      "secret hideaway at one point.  The alcove is fairly large, about thirty feet "+
      "across, and there is a small pile of rubble near the eastern end of the cavern."
    );

    add_item("rubble","A small pile of rocks and bones.  Perhaps you want to check it out?");
    add_item("ledge","Looks like you'll need tools to descend back down unless "
           "you want to risk trying to jump.");
 
    set_exits(([
      "jump" : ROOMS"cave40"
   	]));
    set_invis_exits( ({"jump"}) );
    set_post_exit_functions( ({"jump"}), ({"GoThroughDoor"}) );
    set_climb_exits((["descend":({ ROOMS"cave40",10,6,100})]));
    set_fall_desc(
@FALL
You fall about 20 feet and land on some rocks and other
debris.  Ouch, that hurts!
FALL
);
   	
   set_search("default","That rubble in the back looks worth a closer look.");
   set_search("rubble", (: TO, "search_rubble" :) );
}

void GoThroughDoor() {
//	if(!userp(TP)) return;
	if(avatarp(TP) && TP->query_invis()) return;
   tell_room(ETP,TPQCN+" jumps off the ledge and lands hard below.", TP);
	tell_room(TP,"You jump off the ledge, hitting your head and tumbling "
	    "as you land on the hard ground below.");
   TP->do_damage("torso",random(10)+10);
   return;
}

void reset() {
   ::reset();
   if(random(2))  searched = 0;
   attacked = 0;
}

void search_rubble(string str) {
   object ob;
   if(present("mountain giant")) {
     write("The giant isn't about to let you get the treasure!");
     return;
   }
   if(searched) {
     write("It looks like someone already looted the treasure.");
     return;
   }
   if(!attacked) {
     write("%^BOLD%^You made too much noise!  A giant climbs up to investigate!");
     tell_room(ETP,TPQCN+" searches the rubble but must have made too much noise!  "
        "A giant climbs up to investigate!", TP);
     new("/d/shadow/room/mountain/mons/giant")->move(TO);
     attacked = 1;
     return;
   }
   if(!random(4)) {
       write("All you find are rocks and dirt this time.");
       tell_room(ETP,""+TPQCN+" searches the rubble and looks disappointed.", TP);
       searched = 1;
       return;
   }
   RANDSTUFF->find_stuff(TO,"random");
   RANDSTUFF->treas_chest(TO,2,200);   
   write("%^BOLD%^%^GREEN%^You find a stash of treasure!\n");
   tell_room(ETP,"%^BOLD%^%^GREEN%^"+TPQCN+" finds something in the rubble.", TP);
   searched = 1;
   return;
} 

