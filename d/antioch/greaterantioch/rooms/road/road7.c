#include <std.h>
#include "../../gantioch.h"

inherit ROADINH;

string roomlong, a_long;

void create()
{
        ::create();
      set_long((: TO, "thislong" :));
	  set_exits(([
		"east"  : ROAD"road6",
		//"west"  : ROAD"road8",
		"north" : FOOTHILLS"foothills4",
		"south"	: HAMLET"village1",
]));
roomlong = ROADINH->query_long();
   a_long = " %^BOLD%^%^BLUE%^mountains %^RESET%^%^ORANGE%^loom to the east of here, rising high into the sky."+
            " Surrounding you are expansive, rolling foothills which slowly move out of the ranges to the valley below."+
            " To the southeast you see an outcropping in the rock as the mountains turn"+
            " to foothills and a %^BOLD%^%^WHITE%^keep %^RESET%^%^ORANGE%^sits upon it, seemingly keeping"+
            " watch on the valley below. A large %^BOLD%^%^YELLOW%^structure %^RESET%^%^ORANGE%^stands to the south, alone in the expansive foothills in the"+
            " area. \n\n%^BOLD%^%^CYAN%^The road ends here, under construction to the west,"+
            " however continues back into the mountain pass.";
      set_items(([
        "structure" : "%^RESET%^%^ORANGE%^The building to the south looks like a two-story structure, seemingly"+
		" only protected by the massive keep to the east.",
		"keep" : "%^BOLD%^%^WHITE%^Off a distance to the north, you see large stone keep. Cresting over the"+
		" %^RESET%^%^GREEN%^forest%^BOLD%^%^WHITE%^, it is likely the most prominant structure save the %^RESET%^%^BLUE%^"+
		" mountains %^BOLD%^%^WHITE%^to the east.",
		"plants" : "%^RESET%^%^GREEN%^The grass here stands almost a foot high near the road and various flowers and shrubs also line the path.",
		"mountains" : "%^BOLD%^%^BLUE%^The majestic mountains rise high into the sky, covered in with %^BOLD%^%^WHITE%^snow %^BOLD%^%^BLUE%^and incredibly beautiful.",
		]));
}

string thislong(){
   return roomlong+a_long;
}


