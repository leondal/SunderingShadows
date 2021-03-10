#include "../../undead.h"

inherit INH+"mts_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east":MTS+"lair12",
        "west":MTS+"lair10"
            ]));

}
