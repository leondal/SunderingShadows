#include "../../undead.h"

inherit INH+"mts_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :MTS+"room107",
        "northeast" :MTS+"room64"
             ]));

}
