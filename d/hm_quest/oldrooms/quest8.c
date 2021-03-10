#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_indoors(1);
    set_short("%^BOLD%^%^GREEN%^A treehouse");
    set_long("%^GREEN%^You look around the tree and see it has been made into a treehouse "
        "dwelling.  The branches weave to create walls, and the boughs overhead make a "
        "ceiling.  A bed made of carved wood rests in one corner with blankets tossed "
        "aside.  A small chest rests against the end of the bed.  On one wall a window "
        "is formed, looking out into the tree.  Against the furthest wall sits a table "
        "and a solitary chair.");
    set_exits(([
        "down" : "/d/hm_quest/rooms/quest7"
    ]));
}
