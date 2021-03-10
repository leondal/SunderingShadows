#include <std.h>
#include "../elf.h"
inherit INH"shore";

void create(){
   ::create();
   set_exits(([ "northeast": ROOMS"shore/shore8", 
     "southwest": ROOMS"shore/shore6",
     "south": ROOMS"shore/flow1",
	
     ]));
   set_invis_exits(({"south"}));
       set_search("ice","You take a moment, "+
       "searching out a path through the"+
       " ice.  You think you could go south but it "+
       "is very unstable.  You might fall in the sea!");
}
