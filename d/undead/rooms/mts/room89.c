#include "../../undead.h"

inherit INH+"mts_eight.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :MTS+"room88",
        "west"      :MTS+"room90"
             ]));

}
