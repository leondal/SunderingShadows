#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"room96",
        "west"      :MTS+"room94"
             ]));

}
