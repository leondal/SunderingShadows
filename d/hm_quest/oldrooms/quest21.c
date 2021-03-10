#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_long("%^ORANGE%^You are surrounded now by stands of poplar.  The sky is not "
        "visible nor the way clear.  To the east still lies the pool of sand, so wide "
        "it is almost impossible to make out the trees upon the other side.  You note "
        "once more, the many skeletons lying upon the sand as if polished by a gentle "
        "hand.  You notice a large bough, stripped of leaves and hardened by time, "
        "lying close to the sands edge.");
    set_exits(([
        "southwest" : "/d/hm_quest/rooms/quest22",
        "south" : "/d/hm_quest/rooms/quest20"
    ]));
}
