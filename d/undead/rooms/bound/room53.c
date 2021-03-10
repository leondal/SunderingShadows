#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom31",
        "east"      :BO+"room54",
        "west"      :BO+"room52"
             ]));

}
