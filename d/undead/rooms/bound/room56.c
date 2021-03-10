#include "../../undead.h"

inherit INH+"bound_five.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :BO+"sroom30",
        "west"      :BO+"room57",
        "south"     :BO+"room55"
             ]));

}
