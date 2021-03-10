#include "../../undead.h"

inherit INH+"mts_one.c";

void create() 
{
    ::create();

    set_exits(([
        "up"        :MTS+"lair2",
        "west"      :MTS+"lair4"
            ]));

}
