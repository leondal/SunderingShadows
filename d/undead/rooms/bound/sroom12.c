#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom15",
        "east"      :BO+"sroom11",
        "south"     :BO+"sroom8",
        "west"      :BO+"sroom13"
             ]));

}
