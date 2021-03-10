#include <std.h>
#include "../valley.h"
inherit ROOM;

void create()
{
	::create();
   set_terrain(GRASSLANDS);
   set_travel(FOOT_PATH);
	set_property("light",3);
	set_property("outdoors",3);
	set_short("%^BOLD%^%^WHITE%^Cliff face");
	set_long(
	"%^CYAN%^You've come to the wall of the cliff that the"+
	" %^BOLD%^%^CYAN%^waterfall%^RESET%^%^CYAN%^ is pouring down from. It looks very steep"+
	" and only the most skilled of climbers could hope"+
	" to reach the top. The %^BOLD%^%^CYAN%^waterfall%^RESET%^%^CYAN%^ crashes into the"+
	" %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^ right in front of you"+
        " and %^BOLD%^%^CYAN%^water%^RESET%^%^CYAN%^ is splashed"+
	" onto your face.\n"
	);
	set("night long",
	"%^CYAN%^You're standing at the base of a tall cliff."+
	" The cliff side is very %^BLUE%^sheer%^CYAN%^ and only the most"+
	" skilled of climbers could ever hope to reach"+
	" the top. The %^BOLD%^%^CYAN%^waterfall%^RESET%^%^CYAN%^ cascades down the side"+
	" of the cliff and into the %^BOLD%^%^BLUE%^lake%^RESET%^%^CYAN%^. In the"+
	" %^BOLD%^%^WHITE%^moonlight%^RESET%^%^CYAN%^ the froth of the waterfall looks"+
	" %^BOLD%^%^WHITE%^silver%^RESET%^%^CYAN%^. The wind blows the spray onto your"+
	" face, it's cold and refreshing.\n"
	);
	set_smell("default",
	"You smell the mist from the waterfall."
	);
	set_listen("default",
	"The waterfall's crashing is almost deafening here."
	);
	set_items( ([
	"waterfall" : "%^BOLD%^%^CYAN%^As you stare closer at the waterfall"+
	" you see what appears to be an opening in the"+
	" cliff behind it. You can't reach it from here,"+
	" but perhaps you could from the other side of the"+
	" lake.",
	"cliff" : "%^ORANGE%^The cliff is sheer stone.",
	]) );
	set_exits( ([
	"south" : ROOMS+"shore1",
	]) );
}
