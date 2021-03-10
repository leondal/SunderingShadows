#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    ::create();
    set_long("%^ORANGE%^You breathe a sigh of relief to be away from that hut.  However, it is in "
        "the back of your mind you have yet to see who, or perhaps what, could have done such damage.  "
        "And, what happened to the builder of that little sad hut.");
    set_exits(([
        "northwest" : "/d/hm_quest/rooms/quest27",
        "hut" : "/d/hm_quest/rooms/quest25"
    ]));
}
