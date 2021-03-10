#include "../../undead.h"

inherit INH+"mts_six.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"room56",
        "southwest" :MTS+"room58"
             ]));

}
