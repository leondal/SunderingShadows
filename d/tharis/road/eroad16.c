//eroad16.c

#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create(){
        ::create();
	set_long(
	"        %^BOLD%^%^YELLOW%^The Road leading east from Tharis%^RESET%^\n"+
	"You follow a road destined to lead to the sea, but which must first pass"+
	" past land left untamed by known civilizations. To the east lies the road"+
	" which serves partially as a border between the great forest to the north"+
	" and the mountains which loom large to the south. To the west is Tharis."+
	" Tharis is a rich city. You know that rich cities bring wealth but with"+
	" that wealth bring thieves in great quantity. To the north there appears"+
	" to be a newly formed path. It beckons to all who love adventure.\n"
	);
        set_exits(([
                  "southwest":"/d/tharis/road/eroad15",
                 "east":"/d/tharis/road/eroad17",
                        "path":"/d/tharis/forest/forest1"
        ]));
}
