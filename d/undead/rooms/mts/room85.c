#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :MTS+"room86",
        "south"     :MTS+"room84"
             ]));

}
