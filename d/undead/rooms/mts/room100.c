#include "../../undead.h"

inherit INH+"mts_three.c";

void create() 
{
    ::create();

    set_exits(([
        "bridge"    :MTS+"bridge2",
        "east"      :MTS+"room101"
             ]));

}
