//forest9b.c - Oak tree, second level up

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
The limb you've reached is still large enough to provide good solid footing as long as it's not wet.  Thankfully, rain doesn't penetrate the thick leaves very often.  You can see and hear squirrels scampering around on nearby limbs, some within arm's reach.  Smaller branches are more numerous here and make it a little more difficult to see very much farther into the tree.
STYX
   );
   set_smell("default","The smell of acorns gets stronger.");
   set_listen("default","You hear the squirrels farther up in the tree.");
   set_items( ([ 
   	({"limb","limbs"}):"There are several more sturdy limbs within reach that would probably let you climb higher if you dare.", 
	]) ); 
 	set_exits(([
       	"down":FOREST"forest9a",
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
                write("The limbs give a little and you nearly fall.  After recovering your balance and slowing down, you finally manage to get even higher in the tree.");
                tell_room(ETP,""+TPQCN+" nearly slips and falls but finally manages to climb higher yet.",TP);
                TP->move_player(FOREST"forest9c");
                return 1;
        }
}