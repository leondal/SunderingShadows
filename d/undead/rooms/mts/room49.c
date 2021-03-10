#include "../../undead.h"

inherit INH+"mts_five.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :MTS+"room50",
        "southeast" :MTS+"room48"
             ]));

}
