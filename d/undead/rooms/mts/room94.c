#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :MTS+"room93",
        "east"      :MTS+"room95"
             ]));

}
