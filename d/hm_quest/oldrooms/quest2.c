#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_long("%^ORANGE%^Large rocks begin to appear making your trek a difficult one.  "
        "The path you are travelling on seems to have been used but not frequently as "
        "small bits of scrub grabs at your feet.  You begin to lose sight of the beach "
        "as stands of poplars start to spring up around you.  To the east, larger hills "
        "begin to take shape, covered in wildflowers and bracken.");
    set_exits(([
        "northwest" : "/d/shadow/virtual/sea/hmquest.dock",
        "southeast" : "/d/hm_quest/rooms/quest3",
        "south" : "/d/hm_quest/rooms/quest4"
    ]));
}
