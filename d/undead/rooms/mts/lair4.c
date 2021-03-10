#include "../../undead.h"

inherit INH+"mts_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :MTS+"lair3",
        "west"      :MTS+"lair5"
             ]));

}
