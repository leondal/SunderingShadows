#include "../../undead.h"

inherit INH+"mts_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :MTS+"room48",
        "bridge"    :MTS+"bridge",
        "southwest" :MTS+"room46"
             ]));

}
