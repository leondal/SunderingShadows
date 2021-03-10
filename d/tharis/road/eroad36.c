#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create()
{
	::create();
	set_long(
	"        %^BOLD%^%^YELLOW%^The Road leading east from Tharis%^RESET%^\n"+
	"You follow a road destined to lead to the sea, but which must first pass"+
	" past land left untamed by known civilizations. To the east lies the road"+
	" which serves partially as a border between the great forest to the north"+
	" and the mountains which loom large to the south. To the west is Tharis."+
	" Tharis is a rich city. You know that rich cities bring wealth but with"+
	" that wealth bring thieves in great quantity. There is a little path here"+
	" that leads through the trees to the northwest.\n"
	);
	set_exits(([
	"southwest" : ROOMS+"eroad35",
	"east" : ROOMS+"eroad37",
	"northwest" : ROOMS+"path1",
	]));
}
