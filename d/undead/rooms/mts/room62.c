#include "../../undead.h"

inherit INH+"mts_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"room63",
        "south"     :MTS+"room61"
             ]));

}
