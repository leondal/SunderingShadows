#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom2",
        "south"     :BO+"sroom23"
             ]));

}
