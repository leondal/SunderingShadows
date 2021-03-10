#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"path10",
        "east"      :BO+"sroom13"
             ]));

}
