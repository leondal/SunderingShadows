#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_long("%^ORANGE%^You continue to walk warily along the path.  Bits of bleached bone "
        "lay thrown about, the ends shattered.  Teethmarks from some animal mars the smooth "
        "white patina on the bones.  They look to be from some large animal.  Small insects "
        "chitter and scrabble as they cross your path.  Ahead of you looms a tree of immense "
        "proportions.");
    set_exits(([
        "south" : "/d/hm_quest/rooms/quest7",
        "northeast" : "/d/hm_quest/rooms/quest5"
    ]));
}
