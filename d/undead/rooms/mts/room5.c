#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "northwest" :MTS+"room4",
        "east"      :MTS+"room6"
             ]));

}
