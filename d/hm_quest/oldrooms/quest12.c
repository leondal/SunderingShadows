#include <std.h>

inherit "/d/hm_quest/rooms/quest1.c";

void create()
{
    :: create();
    set_long("%^ORANGE%^The trees continue to thin to the east to let in more "
        "scenes of the sea.  Lower bushes of carigana, throttleleaf and amberberry "
        "replace the stand of poplar.  Small lizards, birds and rodent type creatures "
        "cross your path.  Large hibiscus plants bar your way north, however, the "
        "undulating pond of sand still sits upon your westward side.");
    set_exits(([
        "northwest" : "/d/hm_quest/rooms/quest11",
        "southeast" : "/d/hm_quest/rooms/quest13"
    ]));
}
