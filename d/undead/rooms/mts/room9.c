#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :MTS+"room10",
        "south"     :MTS+"room13",
        "west"      :MTS+"room8"
             ]));

}
