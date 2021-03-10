#include "../../undead.h"

inherit INH+"mts_five.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :MTS+"room49",
        "south"     :MTS+"room47"
             ]));

}
