#include <std.h>
#include "../../gantioch.h"

inherit ROADINH;

string roomlong, a_long;

void create()
{
        ::create();
      set_long((: TO, "thislong" :));
	  set_short(("%^RESET%^%^ORANGE%^A path through the mountains"));
	  set_exits(([
		"northeast"	: "d/antioch/antioch2/rooms/trail6.c",
		"west"	: ROAD"road2",
]));
roomlong = ROADINH->query_long();
   a_long = " %^BOLD%^%^BLUE%^Mountains %^RESET%^%^ORANGE%^surround you here, rising high into the sky."+
            " To the southwest you see an outcropping in the rock as the mountains turn"+
            " to foothills and a %^BOLD%^%^WHITE%^keep %^RESET%^%^ORANGE%^sits upon it, seemingly keeping"+
            " watch on the valley below.\n\n%^BOLD%^%^CYAN%^The road here continues to the west and east"+
            " as it winds its way through the mountain pass. ";
}

string thislong(){
   return roomlong+a_long;
}

//"
       //     as the %^BOLD%^%^BLUE%^mountains%^RESET%^%^ORANGE%^ loom"+
      //     " in the distance to the east. To the west a lush grasslands expands into the open. To the"+
      //     " southeast you see what looks to be a %^BOLD%^%^WHITE%^keep%^RESET%^%^ORANGE%^."+
      //     " To the west you see a small hamlet a distance away.");
