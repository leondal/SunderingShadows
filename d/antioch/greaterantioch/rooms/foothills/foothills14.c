#include <std.h>
#include "../../gantioch.h"
inherit ROOMS"foothills.c";

inherit FOOTHILLSINH;

string roomlong, a_long;

void create()
{
        ::create();
      set_long((: TO, "thislong" :));
	  set_exits(([
	    "north"	: FOOTHILLS"foothills13",
		"south"	: FOOTHILLS"foothills15",
		//"west"	: FOOTHILLS"foothills26",
]));
roomlong = FOOTHILLSINH->query_long();
   a_long = "\n\n%^BOLD%^%^CYAN%^The terrain continues to the west, however the"+
            " terrain is too steep to continue.";
}

string thislong(){
   return roomlong+a_long;
}
