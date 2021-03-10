#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"room66",
        "southwest" :MTS+"room68"
             ]));

}
