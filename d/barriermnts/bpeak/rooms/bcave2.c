//bcave2
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
   set_exits((["northeast":INRMS+"bcave1",
               "southwest":INRMS+"bcave3"]));
   //set_search("shadows",(:TO,"search_pile":));
   set_items((["walls":"The walls of the corridor are carved out of the natural rock of the cliffs.  The rocks are loose and look as though they are ready to fall at any time.  The only thing helping to hold them in place are the few spindly tree trunks that have been propped up against the walls.",
    "ceiling":"The ceiling of the cave is high above you.  The way some of the loose rock hangs make you feel very nervous.",
    "shadows":"%^BOLD%^%^BLACK%^The shadows here are thick and dark, dark enough to conceal whatever may be hiding within them.",
    ({"tree trunks","trunks","trunk","trees","pine trees","pine tree trunks"}):"%^RESET%^%^ORANGE%^A few spindly tree trunks shore up the walls of the corridor. The fact that the root balls are still attached give you the indication that perhaps they have just been ripped out of the ground.%^RESET%^", 
   ]));
}

string ldesc(string str){
   return("%^RESET%^%^BLUE%^You are finally beginning to realize that this is not"
" the place you want to be.  The corridor here is still quite large, being twenty"
" feet in height and about fifteen feet wide, but something feels horribly wrong."
"  Crudely dug out of the side of the mountain and shored with only dead trees,"
" you cannot help but wonder who made this cave and for what purpose.  Rocks"
" crumble around you and seem to get lost in the shadows that appear to be more"
" prevelant in this part of the cave than any other.%^RESET%^ \n");
}
void reset() {
   ::reset();
   query_exit("northwest");
   remove_exit("northwest");
}
void search_pile(){               
   tell_object(TP,"Strange, there seems to be an opening hidden withen the shadows that leads further into the tunnel system.");
   add_exit(INRMS+"dcave1","northwest");
        return ;
}
