#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :MTS+"room77",
        "southeast" :MTS+"room79"
             ]));

}
