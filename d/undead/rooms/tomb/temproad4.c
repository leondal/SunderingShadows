#include "../../undead.h"

inherit INH+"tomb_one.c";

void create() 
{
    ::create();

    set_long( ::query_long() + "%^MAGENTA%^To the north you see the "
        "%^BLUE%^Tomb of Kartakass %^MAGENTA%^towering above the dunes.  "
        "To the south you the Temple Road receeding in the distance.  "
        "You find yourself completely surrounded by dunes of sand.");

    set_exits(([
        "north"     :HALL+"gate",
        "south"     :HALL+"temproad3"
             ]));

}
