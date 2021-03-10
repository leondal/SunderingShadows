#include "../../undead.h"

inherit INH+"mts_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :MTS+"room40",
        "south"     :MTS+"room38"
             ]));

}
