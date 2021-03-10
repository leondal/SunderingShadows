#include "../../undead.h"

inherit INH+"bound_seven.c";

void create() 
{
    ::create();

    set_exits(([
        "west"      :BO+"sroom4",
        "south"     :BO+"sroom2"
             ]));

}
