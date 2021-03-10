#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :BO+"sroom16",
        "south"     :BO+"sroom10"
             ]));

}
