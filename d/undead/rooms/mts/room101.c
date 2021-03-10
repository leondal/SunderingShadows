#include "../../undead.h"

inherit INH+"mts_three.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :MTS+"room102",
        "west"      :MTS+"room100"
             ]));

}
