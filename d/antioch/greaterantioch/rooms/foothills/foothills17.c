#include <std.h>
#include "../../gantioch.h"

inherit FOOTHILLSINH;

string roomlong, a_long;

void create()
{
        ::create();
      set_long((: TO, "thislong" :));
	  set_exits(([
    "north"	: FOOTHILLS"foothills16",
		//"south"	: ROAD"road9",
		//"west"	: ROAD"road10",
                "east"  : FOOTHILLS"foothills3",
                "northwest" : "/d/antioch/jarmila/rooms/1.c",
]));
roomlong = FOOTHILLSINH->query_long();
   a_long = "\n\n%^BOLD%^%^CYAN%^The terrain continues to the west and south, however the"+
            " terrain is too steep to continue.";
}

string thislong(){
   return roomlong+a_long;
}
