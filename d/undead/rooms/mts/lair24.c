#include "../../undead.h"

inherit INH+"mts_one.c";

void create() 
{
    ::create();

    set_exits(([
        "south"     :MTS+"lair25",
        "west"      :MTS+"lair23"
             ]));

}
