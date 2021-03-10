#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "northeast":MTS+"room60",
        "southwest":MTS+"room67"
             ]));

}
