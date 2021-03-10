#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_long("%^ORANGE%^You continue to walk along the beach sand.  There is no way "
        "else for you to make your way around the island but the beachfront.  There "
        "is only a beachfront with thick bushes barring your path in any other direction.  "
        "Here and there large pieces of driftwood have been piled as if to wait for a torch "
        "to light them.  Other than the birds, sealife and occaisional small animal, the "
        "island seems deserted.");
    set_exits(([
        "north" : "/d/hm_quest/rooms/quest14",
        "west" : "/d/hm_quest/rooms/quest16"
    ]));
}
