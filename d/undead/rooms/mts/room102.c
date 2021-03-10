#include "../../undead.h"

inherit INH+"mts_three.c";

void create() 
{
    ::create();

    set_exits(([
        "southeast" :MTS+"room103",
        "west"      :MTS+"room101"
             ]));

}
