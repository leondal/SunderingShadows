#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :MTS+"room68",
        "west"      :MTS+"room70"
             ]));

}
