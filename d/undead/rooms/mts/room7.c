#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"room8",
        "east"      :MTS+"room14",
        "west"      :MTS+"room6"
             ]));

}
