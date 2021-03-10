#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_long("%^ORANGE%^You leave the sea behind as you once more head in a northerly "
        "direction.  You trample through low bushes, back once again into stands of "
        "poplar.  To the east lies the undulating sand, this time movement is seen.  "
        "You see tendrils from low vines dip into the sand as if pulled by an unseen hand.");
    set_exits(([
        "southeast" : "/d/hm_quest/rooms/quest18",
        "north" : "/d/hm_quest/rooms/quest20"
    ]));
}
