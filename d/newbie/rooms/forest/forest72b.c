//forest72b.c - In a ravine

#include <std.h>
#include "../../newbie.h"

inherit ROOM;

void create(){
   ::create();
   set_property("light",3);
   set_property("no teleport",1);
//   set_property("no sticks",1);
   set_short("In a ravine");
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_long(
@STYX
The ravine you've fallen into is about twenty feet deep and runs for about ten yards east and west.  There are a few small bushes growing along the bottom and even up the sides of the ravine.  Roots and rocks also jut out from the sides of the ravine and it looks as though the earth simply split open at some point.  You can see a small opening in the northern wall of the ravine.
STYX
   );
   set_smell("default","There is an earthy smell from the ravine walls.");
   set_listen("default","The dirt walls seem to absorb most sounds.");
   set_items( ([ 
   	({"opening","small opening","wall"}):"The edges of the opening are worn fairly smooth and it's almost large enough for a small animal to fit through.  You might be able to dig enough to get through it.",
	"rocks":"Some of the rocks jutting out are large enough to give you a foothold to climb back up.",
	"roots":"Many of the roots are quite sturdy looking and might provide handholds to climb out."
	]) );
   set_exits(([
        "opening":FOREST"forest72c",
 	]));
   set_invis_exits(([
        "opening":FOREST"forest72c",
    ]));
	TO->collapse_exit("opening");
}

void init() {
        ::init();
        add_action("climb", "climb");
}

int climb(string str) {
        if(TP->query_bound() || TP->query_unconcious() || TP->query_paralyzed() ||
TP->query_tripped()) {
                TP->send_paralyzed_message("info",TP);
                return 1;
        }
        if(!str) {
                write("Climb what?");
                return 1;
        }
        if(str != "wall" && str !="up" && str != "ravine" && str !="out") {
                write("The only direction to climb here is up.");
                return 1;
        }
        else {
                tell_object(TP,"You manage to get handholds and footholds enough to climb up the ravine wall.");
                tell_room(ETP, TPQCN+" uses the roots and rocks for handholds and footholds and begins to climb up.",TP);
                this_player()->move_player(FOREST"forest72");
                return 1;
        }
}
