#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :MTS+"room9",
        "south"     :MTS+"room14",
        "southwest" :MTS+"room7"
             ]));

}
