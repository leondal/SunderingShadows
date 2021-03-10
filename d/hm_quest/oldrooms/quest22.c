#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    ::create();
    set_long("%^ORANGE%^You have left behind you the pit of sand, the poplar stands and "
        "the low scrub.  The area in which you travel now seems damper, with low bushes "
        "sporting hug colourful blossoms.  Larger trees begin to appear along the path, "
        "with huge leaves and vines.  Once again, you have the feeling of many eyes "
        "watching your every move, but you cannot find the bodies that belong to the eyes.");
    set_exits(([
        "west" : "/d/hm_quest/rooms/quest23",
        "northeast" : "/d/hm_quest/rooms/quest21"
    ]));
}
