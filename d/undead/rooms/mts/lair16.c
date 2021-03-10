#include "../../undead.h"

inherit INH+"mts_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :MTS+"lair15",
        "south"     :MTS+"lair17"
             ]));

}
