#include "../../undead.h"

inherit INH+"mts_six.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :MTS+"room53",
        "southeast" :MTS+"room51"
             ]));

}
