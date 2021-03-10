#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom19",
        "west"      :BO+"path12",
        "south"     :BO+"sroom16"
             ]));

}
