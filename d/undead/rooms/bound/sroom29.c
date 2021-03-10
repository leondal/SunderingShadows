#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom25",
        "east"      :BO+"sroom30",
        "west"      :BO+"sroom28"
             ]));

}
