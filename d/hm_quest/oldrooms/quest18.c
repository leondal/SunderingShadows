#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_long("%^ORANGE%^You begin to wonder whether you will make it through this Island "
        "paradise.  No towns, no peoples (of any sort), no fields of grains, or fruit trees "
        "to be readily seen.  Yet somehow, the inhabitants of this tiny island do appear to "
        "survive quite well.  The sound of the surf pounds against the sand like a large drum, "
        "a rhythm forming.  Or is that the surf after all?");
    set_exits(([
        "east" : "/d/hm_quest/rooms/quest17",
        "northwest" : "/d/hm_quest/rooms/quest19"
    ]));
}
