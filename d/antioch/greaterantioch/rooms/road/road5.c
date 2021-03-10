#include <std.h>
#include "../../gantioch.h"

inherit ROADINH;

string roomlong, a_long;

void create()
{
        ::create();
      set_long((: TO, "thislong" :));
	  set_exits(([
		"east"	: ROAD"road4",
		"west"	: ROAD"road6",
		"south" : KEEP"keep1",
]));
roomlong = ROADINH->query_long();
   a_long = " %^BOLD%^%^BLUE%^Mountains %^RESET%^%^ORANGE%^loom around you here, rising high into the sky."+
            " The mountains are slowly ending, slowly turning into rolling foothills to the west. To the south"+
            " you see an outcropping in the rock as the mountains turn"+
            " to foothills and a %^BOLD%^%^WHITE%^keep %^RESET%^%^ORANGE%^sits upon it, seemingly keeping"+
            " watch on the valley below. \n\n%^BOLD%^%^CYAN%^The road here continues to the west and east"+
            " as it winds its way through the mountain pass. ";
}

string thislong(){
   return roomlong+a_long;
}
