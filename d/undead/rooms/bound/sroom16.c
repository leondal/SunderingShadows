#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom18",
        "east"      :BO+"sroom17",
        "south"     :BO+"sroom11",
        "west"      :BO+"sroom15"
             ]));

}
