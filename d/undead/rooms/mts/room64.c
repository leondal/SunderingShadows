#include "../../undead.h"

inherit INH+"mts_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :MTS+"room63",
        "southwest" :MTS+"room65"
             ]));

}
