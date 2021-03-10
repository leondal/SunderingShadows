#include "../../undead.h"

inherit INH+"bound_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :BO+"path11",
        "south"     :BO+"sroom14",
        "west"      :BO+"path9"
            ]));

}
