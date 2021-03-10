#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom11",
        "south"     :BO+"sroom5",
        "west"      :BO+"sroom8"
             ]));

}
