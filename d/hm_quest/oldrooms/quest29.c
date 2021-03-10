#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    ::create();
    set_long("%^ORANGE%^The coast begins to disappear into the quiet forest.  The path "
        "follows to the east, as you seem to be completing a circle.  Rough stone "
        "begins to form a clear path as if leading (or is that herding) you "
        "somewhere to something.  The stone forms a low wall, held together only by "
        "gravity and clinging vines.");
    set_exits(([
        "northeast" : "/d/hm_quest/rooms/quest30",
        "south" : "/d/hm_quest/rooms/quest28"
    ]));
}
