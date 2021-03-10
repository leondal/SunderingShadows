#include "../../undead.h"

inherit INH+"mts_one.c";

void create() 
{
    ::create();

    set_exits(([
        "down"      :MTS+"lair7",
        "east"      :MTS+"lair5"
             ]));

}

