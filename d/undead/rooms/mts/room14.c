#include "../../undead.h"

inherit INH+"mts_two.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :MTS+"room8",
        "east"      :MTS+"room13",
        "west"      :MTS+"room7"
             ]));

}
