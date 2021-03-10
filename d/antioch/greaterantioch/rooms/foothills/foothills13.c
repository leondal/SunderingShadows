#include <std.h>
#include "../../gantioch.h"

inherit FOOTHILLSINH;

string roomlong, a_long;

void create()
{
        ::create();
      set_long((: TO, "thislong" :));
	  set_exits(([
	    "north"	: FOOTHILLS"foothills12",
		"south"	: FOOTHILLS"foothills14",
		//"west"	: FOOTHILLS"foothills25",
]));
roomlong = FOOTHILLSINH->query_long();
   a_long = "\n\n%^BOLD%^%^CYAN%^The terrain continues to the west, however the"+
            " terrain is too steep to continue.";
}

string thislong(){
   return roomlong+a_long;
}





