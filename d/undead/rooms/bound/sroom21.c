#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"path15",
        "west"      :BO+"path14",
        "south"     :BO+"sroom19"
             ]));

}
