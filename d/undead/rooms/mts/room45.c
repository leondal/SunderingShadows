#include "../../undead.h"

inherit INH+"mts_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :MTS+"room46",
        "south"     :MTS+"room44"
             ]));

}
