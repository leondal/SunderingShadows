#include "../../undead.h"

inherit INH+"mts_six.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :MTS+"room54",
        "southeast" :MTS+"room52"
             ]));

}
