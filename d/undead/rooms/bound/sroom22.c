#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"sroom23",
        "south"     :BO+"sroom25"
             ]));

}
