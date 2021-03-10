#include "../../undead.h"

inherit INH+"mts_five.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"room47",
        "south"     :MTS+"room45"
             ]));

}
