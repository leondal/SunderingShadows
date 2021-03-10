#include "../../undead.h"

inherit INH+"mts_one.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :MTS+"lair13",
        "south"     :MTS+"lair15"
             ]));

}
