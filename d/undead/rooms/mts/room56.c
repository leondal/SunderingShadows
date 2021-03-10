#include "../../undead.h"

inherit INH+"mts_six.c";

void create() 
{
    ::create();

    set_exits(([
        "southeast" :MTS+"room55",
        "southwest" :MTS+"room57"
             ]));

}
