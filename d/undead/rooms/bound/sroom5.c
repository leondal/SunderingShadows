#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom7",
        "south"     :BO+"sroom4",
        "west"      :BO+"sroom6"
             ]));

}
