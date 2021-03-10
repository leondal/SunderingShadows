#include "../../undead.h"

inherit INH+"mts_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :MTS+"lair10",
        "south"     :MTS+"lair8"
             ]));

}
