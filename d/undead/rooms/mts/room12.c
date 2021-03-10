#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast" :MTS+"room11",
        "northwest" :MTS+"room13",
        "southwest" :MTS+"room15"
             ]));

}
