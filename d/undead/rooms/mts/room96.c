#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :MTS+"room97",
        "southwest" :MTS+"room95"
             ]));

}
