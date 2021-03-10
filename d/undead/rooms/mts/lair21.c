#include "../../undead.h"

inherit INH+"mts_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :MTS+"lair22",
        "south"     :MTS+"lair20"
             ]));

}
