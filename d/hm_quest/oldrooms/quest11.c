#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_long("%^ORANGE%^The trees break apart to the south of you.  As you look through "
        "them you see a huge bare patch of sand.  Atop the smooth flat sand you see full "
        "skeletons of many forest creatures, and skeletons of some things you cannot name.  "
        "Is it your imagination or does the sand appear to be undulating slightly.");
    set_exits(([
        "west" : "/d/hm_quest/rooms/quest10",
        "southeast" : "/d/hm_quest/rooms/quest12"
    ]));
}
