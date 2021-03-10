#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"room37",
        "northwest" :MTS+"room10",
        "southwest" :MTS+"room12"
             ]));

}
