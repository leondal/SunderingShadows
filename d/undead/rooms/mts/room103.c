#include "../../undead.h"

inherit INH+"mts_three.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :MTS+"room102",
        "southeast" :MTS+"room104"
             ]));

}
