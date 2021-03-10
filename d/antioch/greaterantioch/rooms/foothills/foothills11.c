#include <std.h>
#include "../../gantioch.h"

inherit FOOTHILLSINH;

string roomlong, a_long;

void create()
{
        ::create();
      set_long((: TO, "thislong" :));
	  set_exits(([
		"south"	: FOOTHILLS"foothills12",
		//"west"	: FOOTHILLS"foothills23",
]));
roomlong = FOOTHILLSINH->query_long();
   a_long = "\n\n%^BOLD%^%^CYAN%^The terrain continues to the west, however the"+
            " terrain is too steep to continue.";
}

string thislong(){
   return roomlong+a_long;
}





