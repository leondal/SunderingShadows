#include "../../undead.h"

inherit INH+"bound_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"sroom15",
        "south"     :BO+"sroom13",
        "west"      :BO+"path10",
        "northeast" :BO+"path12"
             ]));

}
