//dcave1
#include <std.h>
#include <rooms.h>
#include "../bpeak.h"
inherit CROOM;



void create(){
::create();
   set_property("light",1);
   set_property("indoors",1);
   set_travel(FOOT_PATH);
   set_terrain(ROCKY);
   set_name("%^BOLD%^%^BLACK%^Inside of a cave%^RESET%^");
   set_short("%^RESET%^Inside of a cave");
   set_long((:TO,"ldesc":));
   set_exits((["southwest":INRMS+"dcave2"]));
   set_search("shadows",(:TO,"search_pile":));
   set_items((["walls":"The walls of the corridor are carved out of the natural rock of the cliffs.  The rocks are loose and look as though they are ready to fall at any time.  The only thing helping to hold them in place are the few spindly tree trunks that have been propped up against the walls.",
    "ceiling":"The ceiling of the cave is high above you.  The way some of the loose rock hangs make you feel very nervous.",
     "shadows":"%^BOLD%^%^BLACK%^The shadows here are darker than any other part of the cave, dark enough to conceal whatever may be hidden within.",
    ({"tree trunks","trunks","trunk","trees","pine trees","pine tree trunks"}):"%^RESET%^%^ORANGE%^A few spindly tree trunks shore up the walls of the corridor. The fact that the root balls are still attached give you the indication that perhaps they have just been ripped out of the ground.%^RESET%^", 
    "roots":"%^RESET%^%^ORANGE%^Bare roots hang down from the ceiling, further evidence of the crude methods from which this tunnel was dug.  ...This definately is not the expert tunneling of any dwarf.",
   ]));
}

string ldesc(string str){
   return("%^RESET%^%^BLUE%^This part of the cave slopes steeply as it winds its way"
" through the mountain.  The bare rock floor is not only wet and slick, making it difficult"
" to keep your footing.  The walls have been shored up with dead tree trunks, and a"
" few roots hang down from the ceiling.  Rocks crumble around you and seem to"
" get lost in the shadows that appear to be more"
" prevelant in this part of the cave than any other.%^RESET%^ \n");
}
void reset() {
   ::reset();
   query_exit("southeast");
   remove_exit("southeast");
}
void search_pile(){               
   tell_object(TP,"Strange, there seems to be an opening hidden withen the shadows that leads further into the tunnel system.");
   add_exit(INRMS+"bcave2","southeast");
        return ;
}
