#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"room",
        "south"     :MTS+"room4"
             ]));

}
