#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_long("%^ORANGE%^You continue to walk warily along the path.  Bits of bleached "
        "bone lay thrown about, the ends shattered.  Teethmarks from some animal mars "
        "the smooth patina finish.  They look to be from some large animal.  Small "
        "insects chitter and scrabble as they cross your path.");
    set_exits( ([
        "west" : "/d/hm_quest/rooms/quest7",
        "southeast" : "/d/hm_quest/rooms/quest10"
    ]) );
}
