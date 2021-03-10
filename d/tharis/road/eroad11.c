#include <std.h>

//inherit ROOM;
#include "../eroad.h"
inherit EROAD;

void create(){
        ::create();
	set_short("Road to the east of Tharis");
	set_long(
	"        %^BOLD%^%^YELLOW%^The Road leading east from Tharis%^RESET%^\n"+
	"You follow a road destined to lead to the sea, but which must first pass"+
	" past land left untamed by known civilizations. To the east lies the road"+
	" which serves partially as a border between the great forest to the north"+
	" and the mountains which loom large to the south. To the west is Tharis."+
	" Tharis is a rich city. You know that rich cities bring wealth but with"+
	" that wealth bring thieves in great quantity.\n\n"+
	"You notice some movement to the north.\n"
	);
        set_exits(([
                "southwest":"/d/tharis/road/eroad10",
                "east":"/d/tharis/road/eroad12",
      "north" : "/d/shadow/room/city/cguild/ranger/rooms/path1",
        ]));
    set_items( ([
      ({"north", "trees", "voices"}) : "To the north as you examine the trees, you notice that one large one is an illusion!  Behind it you can see a path leading north.",
    ]) );
        set_smell("default","Hints of the forest to the north reach you nostrils.");
    set_listen("default", "You think you can hear voices.");
    set_listen("voices", "You can't make out exactly what the voices are saying, but you can tell they are coming from the north.");
    set_invis_exits( ({"north"}) );
}
