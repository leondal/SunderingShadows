#include <std.h>
#include "../argabbr.h"
inherit INH+"shore";

void create() {
    ::create();
   set_exits( ([
                "north":SHO+"shore7",
				"south":SHO+"shore9"]) );

 set_search("water",(:TO,"search_water":));   
 set_search("default","The water seems odd here.");
}
//entrance to ship building area 

int search_water(string str){
     object obj;
	 
     tell_object(TP,"It seems like there is quite a bit of fresh water flowing into the sea from under the rocks.");
 
      return 1;
}
