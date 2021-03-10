#include "../../undead.h"

inherit INH+"mts_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "southwest" :MTS+"room62",
        "southeast" :MTS+"room64"
             ]));

}
