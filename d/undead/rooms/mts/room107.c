#include "../../undead.h"

inherit INH+"mts_seven.c";

void create() 
{
    ::create();

    set_long( ::query_long() + "  In front of you you see the path "
        "begin to descend into the valley below, a thick fog covers the valley, "
        "making it impossible to see what is below.");

    set_exits(([
        "down"      :SWMP+"swamp1",
        "south"     :MTS+"room65"
             ]));

}
