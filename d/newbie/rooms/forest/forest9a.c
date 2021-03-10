//forest9a.c - Oak tree, first branch up

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",2);
   set_property("no teleport",1);
   set_property("no sticks",1);
   set_short("%^GREEN%^In the Massive Oak Tree%^RESET%^");
   set_terrain(BRANCHES);
   set_travel(FRESH_BLAZE);
   set_long(
@STYX
You've managed to climb to the lower limbs of the massive oak tree.  Looking down, you realize the sparse grass won't provide any cushion if you fall and a tumble onto those exposed roots could really hurt.  There is another limb about three feet up that would also be sturdy enough to stand on.  You might manage to climb on up to it since you got this far.
STYX
   );
   set_smell("default","The smell of acorns gets stronger.");
   set_listen("default","You hear the squirrels farther up in the tree.");
   set_items( ([ 
   	({"limb","limbs"}):"These lower limbs are large enough to stand on comfortably and nearby limbs give you plenty to hold on to and keep your balance.", 
	]) ); 
 	set_exits(([
       	"down":FOREST"forest9",
       ]) );
}
   void init()
{
        ::init();
        add_action("climb", "climb");
}

int climb(string str)
{
        if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() ||
TP->query_tripped()) {
                TP->send_paralyzed_message("info",TP);
                return 1;
        }
        
        else {
                write("The limbs are sturdy and plentiful enough you succeed in climbing higher.");
                tell_room(ETP,""+TPQCN+" grabs the sturdy limbs and climbs even higher.",TP);
                TP->move_player(FOREST"forest9b");
                return 1;
        }
}