#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    ::create();
    set_short("%^ORANGE%^A pathway");
    set_long("%^ORANGE%^You leave the sea behind as you once more head in a northerly "
        "direction.  You trample through low bushes, back once again into the stands "
        "of poplar.  To the east lies the undulating sand, this time movement is seen.  "
        "You see tendrils slipping from low vines to slowly be tugged into the sand, as "
        "if pulled by an unseen hand.");
    set_exits( ([
        "south" : "/d/hm_quest/rooms/quest19",
        "north" : "/d/hm_quest/rooms/quest21"
    ]) );
}
