//ice
#include <std.h>
#include "elf.h"
inherit INH"ice";

void create(){
   ::create();
   set_exits(([ "southwest": ROOMS"ice12", 
      "west": ROOMS"ice10",                  
	  "up": ROOMS"ruin1", 
         ]));
set_invis_exits(({"up"}));
set_search("room",(:TO,"search_room":));   
}
int search_room(string str){
     tell_object(TP,"It looks like one could go"+
         " <up> along the ice here.");
      return 1;
}
