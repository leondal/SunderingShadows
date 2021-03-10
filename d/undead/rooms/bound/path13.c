#include "../../undead.h"

inherit INH+"bound_two.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"path14",
        "east"      :BO+"sroom19",
        "south"     :BO+"path12"
             ]));

}
