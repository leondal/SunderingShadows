//cave77.c
#include <std.h>
#include "echoes.h"

inherit OGRES;

void create(){
    ::create();
    set_long(""+TO->query_long()+"A %^BOLD%^%^BLACK%^large, black hole "+
       "%^RESET%^takes up part of the floor near the southern wall.\n");
    set_exits(([
        "north" : ROOMS"cave76",
        "down" : ROOMS"cave27",
   	]));
    add_item("hole","Looking closer, you can see a room below.  There are large rocks "+
	      "piled up, creating a crude and most likely treacherous stairway.");
	    
    set_post_exit_functions( ({"down"}), ({"GoThroughDoor"}) );
}
void GoThroughDoor() {
//	if(!userp(TP)) return;
	if(avatarp(TP) && TP->query_invis()) return;
	if(!random(4)) {
	  tell_room(ETP,TPQCN+" slips and falls trying to pick a way down the "
	     "pile of rocks.", TP);
	  tell_room(TP,"You slip and fall trying to pick a way down the pile of rocks!"
	     "\n%^BLUE%^Tumbling the rest of the way down leaves you badly bruised.");
     TP->do_damage("torso",random(6)+8);
     return;
   }
   return;
}	
